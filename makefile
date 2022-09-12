include UnitTestRunner/UnitTestRunner.mk
include UnitTest/UnitTest.mk
include Unit/Unit.mk

#SHELL := pwsh.exe

MKDIR   := mkdir
RMDIR   := rm -rf
CC      := gcc
BIN     := ./bin
OBJ     := ./obj
COV     := ./coverage
LIB	 	:= ./UnitTestRunner/lib
OBJS    := $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS) $(UNITOBJS)
EXE     := $(BIN)/main.exe
CFLAGS  := -g -I$(UNITESTRUNNERINCLUDE) -I$(UNITESTINCLUDE) -I$(UNITINCLUDE) -Wall
COVFLAGS:= -fprofile-arcs -ftest-coverage
LDFLAGS := -lgcov --coverage -L$(LIB)
LDLIBS  := -lm -lpdcurses

.PHONY: all run clean coverage

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
	$(MKDIR) $@

run: $(EXE) | $(COV)
	echo "Running $<"
	$<
	gcovr -r . --html --html-details -o $(COV)/index.html

clean:
	$(RMDIR) $(OBJ) $(BIN) $(COV)


#coverage: $(EXE)
#	echo "Running $<"
#	$<
#	