include UnitTestRunner/UnitTestRunner.mk
include UnitTest/UnitTest.mk
include Unit/Unit.mk

MKDIR   := mkdir
RMDIR   := rm -rf
CC      := gcc
BIN     := ./bin
OBJ     := ./obj
COV     := ./cov
LIB	 	:= ./UnitTestRunner/lib
OBJS    := $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS) $(UNITOBJS)
EXE     := $(BIN)/main.exe
CFLAGS  := -g -Wall -MMD -I$(UNITESTRUNNERINCLUDE) -I$(UNITESTINCLUDE) -I$(UNITINCLUDE)
COVFLAGS:= -fprofile-arcs -ftest-coverage
LDFLAGS := -lgcov --coverage -L$(LIB)
LDLIBS  := -lm -lpdcurses

# Include the dependency files
-include $(OBJS:%.o=%.d)

.PHONY: all run coverage clean 

# Build the executable
all: $(EXE)

# Link the executable
$(EXE): $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS) $(UNITOBJS) | $(BIN)
	echo Linking $@
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

# Compile the UnitTestRunner source files
$(UNITTESTRUNNEROBJS): $(OBJ)/%.o: $(UNITTESTRUNNERSRC)/%.c | $(OBJ)
	echo Compiling $<
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the UnitTest source files
$(UNITTESTOBJS): $(OBJ)/%.o: $(UNITTESTSRC)/%.c | $(OBJ)
	echo Compiling $<
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the Unit source files
$(UNITOBJS): $(OBJ)/%.o: $(UNITSRC)/%.c | $(OBJ)
	echo Compiling $<
	$(CC) $(CFLAGS) $(COVFLAGS) -c $< -o $@

# Create needed directories
$(BIN) $(OBJ) $(COV):
	$(MKDIR) -p $@

# Run the executable
run: $(EXE)
	echo "Running $<"
	$< ${TESTAPPARGS}

# Run the executable with coverage analysis with summary on stdout
coverage: clean run | $(COV)
	gcovr -r . -s

# Run the executable with coverage analysis with html output
coverage-html: clean run | $(COV)
	gcovr -r . --html --html-details -o ${COV}/index.html

# Clean the build
clean:
	$(RMDIR) $(OBJ) $(BIN) $(COV) *.txt

# End of makefile