include UnitTestRunner/UnitTestRunner.mk
include UnitTest/UnitTest.mk

#SHELL := pwsh.exe

MKDIR   := mkdir
RMDIR   := rm -rf
CC      := gcc
BIN     := ./bin
OBJ     := ./obj
COV     := ./coverage
LIB	 	:= ./UnitTestRunner/lib
OBJS    := $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS)
EXE     := $(BIN)/main.exe
CFLAGS  := -g -I$(UNITESTRUNNERINCLUDE) -I$(UNITESTINCLUDE) -fprofile-arcs -ftest-coverage -Wall
LDFLAGS := -lgcov --coverage -L$(LIB)
LDLIBS  := -lm -lpdcurses

.PHONY: all run clean coverage

all: $(EXE)

$(EXE): $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS) | $(BIN)
	echo Linking $@
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(UNITTESTRUNNEROBJS): $(OBJ)/%.o: $(UNITTESTRUNNERSRC)/%.c | $(OBJ)
	echo Compiling $<
	$(CC) $(CFLAGS) -c $< -o $@

$(UNITTESTOBJS): $(OBJ)/%.o: $(UNITTESTSRC)/%.c | $(OBJ)
	echo Compiling $<
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ) $(COV):
	$(MKDIR) $@

run: $(EXE)
	echo "Running $<"
	$<



clean:
	$(RMDIR) $(OBJ) $(BIN) $(COV)