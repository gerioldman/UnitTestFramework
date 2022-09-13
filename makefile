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
CFLAGS  := -g -I$(UNITESTRUNNERINCLUDE) -I$(UNITESTINCLUDE) -I$(UNITINCLUDE) -Wall
COVFLAGS:= -fprofile-arcs -ftest-coverage
LDFLAGS := -lgcov --coverage -L$(LIB)
LDLIBS  := -lm -lpdcurses

.PHONY: all run coverage clean 

all: $(EXE)

$(EXE): $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS) $(UNITOBJS) | $(BIN)
	echo Linking $@
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(UNITTESTRUNNEROBJS): $(OBJ)/%.o: $(UNITTESTRUNNERSRC)/%.c | $(OBJ)
	echo Compiling $<
	$(CC) $(CFLAGS) -c $< -o $@

$(UNITTESTOBJS): $(OBJ)/%.o: $(UNITTESTSRC)/%.c | $(OBJ)
	echo Compiling $<
	$(CC) $(CFLAGS) -c $< -o $@

$(UNITOBJS): $(OBJ)/%.o: $(UNITSRC)/%.c | $(OBJ)
	echo Compiling $<
	$(CC) $(CFLAGS) $(COVFLAGS) -c $< -o $@

$(BIN) $(OBJ) $(COV):
	$(MKDIR) -p $@

run: $(EXE)
	echo "Running $<"
	$< ${TESTAPPARGS}

coverage: run | $(COV)
	gcovr -r . --html --html-details -o ${COV}/index.html

clean:
	$(RMDIR) $(OBJ) $(BIN) $(COV)

# End of makefile