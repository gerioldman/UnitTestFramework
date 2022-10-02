
from email import generator, header
from msvcrt import getch
import sys
import curses
import os
import re
from tokenize import group

from pycparser import parse_file, c_ast, c_generator
import pprint as pp


# return the header file name from the file path
def returnHeaderName(coord):
    origin = re.search("[^\\/]+\.h",coord.file)
    if hasattr(origin,"group"):
        return origin.group()
    else:
        return None


# get list of typedefs from AST
def getListofTypedef(ast):
    typedefList = []
    for entity in ast.ext:
        if isinstance(entity, c_ast.Typedef) and returnHeaderName(entity.coord) != '_fake_typedefs.h':
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

def getListofFuncDecl(ast):
    declList = []
    for entity in ast.ext:
        if hasattr(entity, "type"):
            if isinstance(entity.type, c_ast.FuncDecl):
                declList.append(entity)
    return declList

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
        if not defined and isinstance(entity.type, c_ast.FuncDecl):
            funcDeclList.append(entity)
    return funcDeclList

# get list of function declarations with definitions
def getListofFuncWithDefinition(declList, funcDefL):
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
        if defined and isinstance(entity.type, c_ast.FuncDecl):
            funcDeclList.append(entity)
    return funcDeclList



# get list of header files from the list of function declarations
def getHeaderList(declList):
    headerList = []
    for element in declList:
        if hasattr(element,"coord"):
            headerName = returnHeaderName(element.coord)
            if headerName != None:
                if headerName not in headerList and headerName != "_fake_typedefs.h":
                    headerList.append(headerName)
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

def makeTypeStubHeader(ast):
    typedefList = getListofTypedef(ast)
    header_list = getHeaderList(ast)
    local_ast = c_ast.FileAST(typedefList)
    test_stub = c_ast.Typedef(name='TEST_STUB_TYPE',
                                    quals=['extern'],
                                    type=c_ast.TypeDecl(   declname='TEST_STUB_TYPE',
                                                            align= None,
                                                            quals=[],
                                                            type= c_ast.Struct(name=None,decls=[],coord=None),
                                                            coord=None),
                                    coord=None,
                                    storage=['typedef'])
    for entity in ast.ext:
        for header in header_list:
            if returnHeaderName(entity.coord) == header:
                stub = makeStubStruct(entity)
                if stub != None:
                    stub_part = c_ast.Decl( name = entity.name,
                                            quals = [],
                                            storage = [],
                                            funcspec = [],
                                            align=None,
                                            type = c_ast.TypeDecl(  declname = entity.name,
                                                                    quals = [],
                                                                    type = c_ast.IdentifierType(names=[ stub.name ]),
                                                                    coord = None,
                                                                    align = None),
                                            init = None,
                                            bitsize = None,
                                            coord = None)
                    test_stub.type.type.decls.append(stub_part)
                    local_ast.ext.append(stub)

    local_ast.ext.append(test_stub)
    local_ast.ext.append(c_ast.Typedef(name='TEST_STUB',
                                    quals=[],   
                                    type=c_ast.TypeDecl(   declname='TEST_STUB',
                                                            align= None,
                                                            quals=[],
                                                            type= c_ast.IdentifierType(names=['TEST_STUB_TYPE']),
                                                            coord=None),
                                    coord=None,
                                    storage=['extern']))
    
    makeHeaderFile("types.h", local_ast)
"""
    This function creates the stub source file for the Unit Test

    @param ast: AST of the source file to generate the stubs for
    @param header_list: list of header files to include in the stub source file
"""
def makeStubSource(ast, header_list):
    declList = getListofDecl(ast)
    funcDefList = getListofFuncDef(ast)
    funcDeclList = getListofFuncWithoutDefinition(declList, funcDefList)
    local_ast = c_ast.FileAST([])
    local_ast.ext.append(c_ast.Decl(   name='TEST_STUB',
                                            quals=[],
                                            storage=[],
                                            funcspec=[],
                                            align=None,
                                            type=c_ast.TypeDecl(    declname='TEST_STUB',
                                                                    align=None,     
                                                                    quals=[],
                                                                    type=c_ast.IdentifierType(names=['TEST_STUB_TYPE']),
                                                                    coord=None),
                                            init=None,
                                            bitsize=None,
                                            coord=None))
    for entity in funcDeclList:
        if isinstance(entity.type, c_ast.FuncDecl):
            funcDef = c_ast.FuncDef(decl=entity,param_decls=None,body=c_ast.Compound(block_items=[]))
            local_ast.ext.append(funcDef)

    funcDeclList = getListofFuncWithDefinition(declList, funcDefList)

    for entity in funcDeclList:
        if isinstance(entity.type, c_ast.FuncDecl):
            funcDef = c_ast.FuncDef(decl= c_ast.Decl(
                                                        name='TEST_CALL_' + entity.name,
                                                        quals=entity.quals,
                                                        align=entity.align,
                                                        bitsize=entity.bitsize,
                                                        storage=entity.storage,
                                                        funcspec=entity.funcspec,
                                                        type= c_ast.FuncDecl(   args= entity.type.args,
                                                                                type= c_ast.TypeDecl(   declname= 'TEST_CALL_' + entity.type.type.declname,
                                                                                                        quals= entity.type.type.quals,
                                                                                                        type= entity.type.type.type,
                                                                                                        coord= entity.type.type.coord,
                                                                                                        align= entity.type.type.align),
                                                                                coord=entity.type.coord),
                                                        init=entity.init,
                                                        coord=entity.coord),
                                    param_decls=None,
                                    body=c_ast.Compound(block_items=[]))
            local_ast.ext.append(funcDef)
    

    generator = c_generator.CGenerator()
    f = open("UnitTest/src/stubs/stub.c" , "w")
    f.write(
"/**\n\
* @file stub.c\n\
*\n\
* @brief This file contains the stubs for the functions\n\
*\n\
*/\n")
    f.write("#include \"types.h\"\n")
    for header in header_list:
        f.write("#include \"" + header + "\"\n")
    f.write(generator.visit(local_ast))
    f.close()

# TODO: make a class for the stub generator

# create the required header file
def makeHeaderFile(name, ast):
    generator = c_generator.CGenerator()
    # open the file for writing
    f = open("UnitTest/include/stubs/" + name, "w")
    # header guard
    f.write("#ifndef " + name[0:-2].upper() + "_H\n")
    f.write("#define " + name[0:-2].upper() + "_H\n")
    f.write("\n")
    # include types.h if created header is not types.h
    if name != "types.h":
        f.write("#include \"types.h\"\n")
    # write the header file
    f.write(generator.visit(ast))
    # close the header guard
    f.write("\n")
    f.write("#endif /* " + name[0:-2].upper() + "_H */")
    # close the file
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
            
            struct.decls.append(c_ast.Decl( name = "redirectFuncPtr",
                                            align=[],
                                            bitsize=None,
                                            coord=None,
                                            funcspec=[],
                                            init=None,
                                            quals=[],
                                            storage=[],
                                            type=c_ast.PtrDecl( quals=[],
                                                                type=c_ast.FuncDecl(    args=entity.type.args,
                                                                                        type= c_ast.TypeDecl(   declname='redirectFuncPtr',
                                                                                                                align=entity.type.type.align,
                                                                                                                quals=entity.type.type.quals,
                                                                                                                type=entity.type.type.type,
                                                                                                                coord=entity.type.type.coord),
                                                                                        coord=entity.coord),
                                                                coord=None)))
            typedef.type.type = struct
            c_ast.PtrDecl(  quals=[],
                            type= entity.type,
                            coord=None,)
            
            typedef.type.type = struct
    return typedef


# main entry point
def main():
    if len(sys.argv) > 1:
        ast = parse_file(sys.argv[1], use_cpp=True, cpp_path='gcc', cpp_args=['-E','-nostdinc',r'-IUnit/include', r'-IC:\\Python310\\Lib\site-packages\\pycparser\\utils\\fake_libc_include'])

        # get list of function declarations from include files
        typedefList = getListofTypedef(ast)

        # get list of declarations
        declList = getListofDecl(ast)

        # get list of header files from the ast tree
        headerList = getHeaderList(ast.ext)

        # create the folder structure for the unit test
        createFolder()

        # create the type stub header file
        makeTypeStubHeader(ast)

        # create the header stub files
        makeStubSource(ast, headerList)

        ################################
        funcDeclList = getListofFuncDecl(ast)
        # headerstubbed = getListofFuncWithoutDefinition(declList, funcDefL)
#
        for header in headerList:
            header_ast = c_ast.FileAST([])
            for entity in funcDeclList:
                if returnHeaderName(entity.coord) == header:
                    header_ast.ext.append(entity)
            makeHeaderFile(header, header_ast)

        # Create stub header which contains every generated header

        f = open("UnitTest/include/stubs/stub.h" , "w")
        f.write("#ifndef STUB_H\n")
        f.write("#define STUB_H\n")
        f.write("#include \"types.h\"\n")
        for header in headerList:
            f.write("#include \"" + header + "\"\n")

        funcDefList = getListofFuncDef(ast)
        unitFuncList = getListofFuncWithDefinition(declList, funcDefList)
        for entity in unitFuncList:
            entity.name = "TEST_CALL_" + entity.name
            entity.type.type.declname = "TEST_CALL_" + entity.type.type.declname
        generator = c_generator.CGenerator()
        header_ast = c_ast.FileAST(unitFuncList)
        f.write(generator.visit(header_ast))
        f.write("#endif /* STUB_H */")
        
        f.close()

    else:
        print('Please specify filename')

if __name__ == "__main__":
    main()