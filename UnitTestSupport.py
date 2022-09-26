
from msvcrt import getch
import sys
import curses
import os
import re

from pycparser import parse_file, c_ast, c_generator
import pprint as pp

# get list of typedefs from AST
def getListofTypedef(ast):
    typedefList = []
    for entity in ast.ext:
        if isinstance(entity, c_ast.Typedef):
            typedefList.append(entity)
    return typedefList

# get list of function declarations from AST
def getListofDecl(ast):
    declList = []
    for entity in ast.ext:
        if isinstance(entity, c_ast.Decl):
            declList.append(entity)
    return declList

# get list of function definitions from AST
def getListofFuncDef(ast):
    funcDefList = []
    for entity in ast.ext:
        if isinstance(entity, c_ast.FuncDef):
            funcDefList.append(entity)
    return funcDefList

# get list of function declarations without definitions
def getListofFuncWithoutDefinition(declList, funcDefL):
    funcDeclList = []
    for entity in declList:
        defined = False
        for funcDef in funcDefL:
            # Is this a function definition?
            if isinstance(funcDef, c_ast.FuncDef):
                # Is this the function definition for the function declaration?
                if funcDef.decl.name == entity.name:
                    defined = True
                    break
        # append the function declaration if it is not defined
        if not defined:
            funcDeclList.append(entity)
    return funcDeclList

def getListofDecl(ast):
    declList = []
    for entity in ast.ext:
        if isinstance(entity, c_ast.Decl):
            declList.append(entity)
    return declList

# return the header file name from the file path
def returnHeaderName(coord):
    origin = re.search("[^\\/]+.h",coord.file)
    return origin.group()

# get list of header files from the list of function declarations
def getHeaderList(declList):
    headerList = []
    for element in declList:
        headerList.append(returnHeaderName(element.coord))
    headerList = list(set(headerList))
    return headerList

# create the folder structure for the unit test
def createFolder():
    if( os.path.isdir("UnitTest") == False):
        os.mkdir("UnitTest")
    if( os.path.isdir("UnitTest/include") == False):
        os.mkdir("UnitTest/include")
    if( os.path.isdir("UnitTest/include/stubs") == False):
        os.mkdir("UnitTest/include/stubs")
    if( os.path.isdir("UnitTest/src") == False):
        os.mkdir("UnitTest/src")
    if( os.path.isdir("UnitTest/src/stubs") == False):
        os.mkdir("UnitTest/src/stubs")

# create the required header file
def makeHeaderFile(name, ast):
    generator = c_generator.CGenerator()
    # open the file for writing
    f = open("UnitTest/include/stubs/" + name, "w")
    # header guard
    f.write("#ifndef " + name[0:-2].upper() + "_H\n")
    f.write("#define " + name[0:-2].upper() + "_H\n")
    f.write("\n")
    # write the header file
    f.write(generator.visit(ast))
    # close the header guard
    f.write("\n")
    f.write("#endif /* " + name[0:-2].upper() + "_H */")
    # close the file
    f.close()

def makeSourceFile(ast,headerList):
    generator = c_generator.CGenerator()
    f = open("UnitTest/src/stubs/stub.c" , "w")
    for header in headerList:
        f.write("#include \"" + header + "\"\n")
    f.write(generator.visit(ast))
    f.close()

# create stub struct for the function declaration
def makeStubStruct(entity):
    struct = None
    typedef = None
    if isinstance(entity, c_ast.Decl):
        if isinstance(entity.type, c_ast.FuncDecl):
            typedef = c_ast.Typedef(name='TEST_STUB_' + entity.name + '_TYPE',
                                    quals=None,
                                    type=c_ast.TypeDecl(   declname='TEST_STUB_' + entity.name + '_TYPE',
                                                            align= None,
                                                            quals=[],
                                                            type= None,
                                                            coord=entity.coord),
                                    coord=entity.coord,
                                    storage=['typedef'])
            struct = c_ast.Struct(name=None,decls=[],coord=None)
            struct.decls.append(c_ast.Decl( name='callcount',
                                            quals=[],
                                            align=[],
                                            storage=[],
                                            funcspec = [],
                                            type = c_ast.TypeDecl(  align=None,
                                                                    coord=None,
                                                                    declname='callcount',
                                                                    quals=[],
                                                                    type=c_ast.IdentifierType(names=['unsigned','long'])),
                                            init=None,
                                            bitsize=None))
            if entity.type.type.type.names[0] != 'void':
                struct.decls.append(c_ast.Decl( name='returnValue',
                                                quals=[],
                                                align=[],
                                                storage=[],
                                                funcspec = None,
                                                type = c_ast.TypeDecl(  'returnValue',
                                                                        entity.type.type.quals,
                                                                        entity.type.type.align,
                                                                        entity.type.type.type,
                                                                        entity.type.type.coord),
                                                init=None,
                                                bitsize=None))
            if entity.type.args != None:
                for arg in entity.type.args.params:
                    if arg.type.type.names[0] != 'void':
                        struct.decls.append(arg)
            typedef.type.type = struct
            #struct.decls.append(c_ast.Decl('TEST_STUB_' + entity.name + '_RETURN_VALUE',[],[],[],entity.type.type,None,None))
                #struct.decls.append(c_ast.Typedef(entity.type.type,'TEST_STUB_' + entity.name + '_RETURN_TYPE'))
    return typedef #struct

# main entry point
def main():
    if len(sys.argv) > 1:
        ast = parse_file(sys.argv[1], use_cpp=False)
        # get list of function declarations from include files
        typedefList = getListofTypedef(ast)

        funcDeclList = getListofDecl(ast)

        mergedList = typedefList + funcDeclList

        # get list of header files from the list of function declarations
        headerList = getHeaderList(mergedList)

        # create the folder structure for the unit test
        createFolder()

        # create the required header file
        for header in headerList:
            header_ast = c_ast.FileAST([])
            for entity in mergedList:
                if returnHeaderName(entity.coord) == header:
                    header_ast.ext.append(entity)
                    stub = makeStubStruct(entity)
                    if stub != None:
                        header_ast.ext.append(stub)
            makeHeaderFile(header, header_ast)
        
        header_ast = []

        declList = getListofDecl(ast)
        funcDefL = getListofFuncDef(ast)
        funcDeclList = getListofFuncWithoutDefinition(declList, funcDefL)
        mergedList = typedefList + funcDeclList
        headerList = getHeaderList(mergedList)

        for header in headerList:
            header_ast = c_ast.FileAST([])
            for entity in mergedList:
                if returnHeaderName(entity.coord) == header:
                    header_ast.ext.append(entity)

        # create the required source file
        source_ast = c_ast.FileAST([])
        for entity in header_ast.ext:
            if isinstance(entity, c_ast.Decl):
                for child in entity:
                    if isinstance(child, c_ast.FuncDecl):
                        funcDef = c_ast.FuncDef(decl=entity,param_decls=None,body=c_ast.Compound(block_items=[]))
                        source_ast.ext.append(funcDef)
        makeSourceFile( source_ast,headerList)

    else:
        print('Please specify filename')

if __name__ == "__main__":
    main()
