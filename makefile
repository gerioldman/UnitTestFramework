include UnitTestRunner/UnitTestRunner.mk
include UnitTest/UnitTest.mk
include Unit/Unit.mk

MKDIR   := mkdir
RMDIR   := rm -rf
CC      := gcc
PYTHON  := python
UNITSTUBGEN := ./UnitTestSupport.py
BIN     := ./bin
OBJ     := ./obj
COV     := ./cov
PRE     := ./pre
LIB	 	:= ./UnitTestRunner/lib
OBJS    := $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS) $(UNITOBJS)
EXE     := $(BIN)/main.exe
CFLAGS  := -g -Wall -MMD -fprofile-abs-path -I$(UNITESTRUNNERINCLUDE) -I$(UNITESTINCLUDE) -I$(UNITTESTSTUBINCLUDE)
PREFLAGS:= -I$(UNITINCLUDE) -DUNITTEST=1
COVFLAGS:= -fprofile-arcs -ftest-coverage
LDFLAGS := -lgcov --coverage -L$(LIB)
LDLIBS  := -lm

TESTAPPARGS ?= --colour -a -s

# Include the dependency files
-include $(OBJS:%.o=%.d)

.PHONY: all run coverage coverage-html clean stubgen check


# Check for dependencies
check: 
	echo "# Check for Compiler:"
	$(CC) --version
	echo "# Check for Python:"
	$(PYTHON) --version
	echo "# Check for gcovr:"
	gcovr --version

# Build the executable
all: $(EXE)

# Link the executable
$(EXE): $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS) $(UNITTESTSTUBOBJS) $(UNITOBJS) | $(BIN)
	echo "# Linking $@"
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

# Compile the UnitTestRunner source files
$(UNITTESTRUNNEROBJS): $(OBJ)/%.o: $(UNITTESTRUNNERSRC)/%.c | $(OBJ)
	echo "# Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the UnitTest source files
$(UNITTESTOBJS): $(OBJ)/%.o: $(UNITTESTSRC)/%.c | $(OBJ)
	echo "# Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the Unit source files
$(UNITOBJS): $(OBJ)/%.o: $(UNITSRC)/%.c | $(OBJ)
	echo "# Compiling $<"
	$(CC) $(CFLAGS) $(COVFLAGS) -c $< -o $@

$(UNITTESTSTUBOBJS): $(OBJ)/%.o: $(UNITTESTSTUBSRC)/%.c | $(OBJ)
	echo "# Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Create the stubs for the UnitTest	
stubgen:
	echo # Generating unit stubs
	$(PYTHON) $(UNITSTUBGEN) $(UNITSOURCE)

# Create needed directories
$(BIN) $(OBJ) $(COV) $(PRE):
	$(MKDIR) -p $@

# Run the executable
run: $(EXE)
	echo "# Running $<"
	$< ${TESTAPPARGS}

# Run the executable with coverage analysis with summary on stdout
coverage: run | $(COV)
	echo "# Running coverage analysis"
	gcovr -r . -s

# Run the executable with coverage analysis with html output
coverage-html: run | $(COV)
	echo "# Running coverage analysis with html output"
	gcovr -r . --html --html-details -o ${COV}/index.html

# Preprocess the source files for automatic unit stub generation
#$(UNITPREPARE): $(PRE)/%.i: $(UNITSRC)/%.c | $(PRE)
#	echo "# Preprocessing $<"
#	$(CC) $(PREFLAGS) -E $< -o $@

# Generate the unit stubs
# preprocess: $(UNITPREPARE)


# Clean the build
clean:
	echo "# Cleaning" 
	$(RMDIR) $(OBJ) $(BIN) $(COV) $(PRE) *.txt  
#$(UNITTESTSTUBINCLUDE)/*.h $(UNITTESTSTUBSRC)/*.c

# End of makefile