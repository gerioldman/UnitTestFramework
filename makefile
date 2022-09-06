include UnitTestRunner/UnitTestRunner.mk
include UnitTest/UnitTest.mk

#SHELL := "C:\Program Files\PowerShell\7\pwsh.exe"

MKDIR   := mkdir
RMDIR   := rm -rf
CC      := mingw32-gcc
BIN     := ./bin
OBJ     := ./obj
COV     := ./coverage
OBJS    := $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS)
EXE     := $(BIN)/main.exe
CFLAGS  := -g -I$(UNITESTRUNNERINCLUDE) -I$(UNITESTINCLUDE) -fprofile-arcs -ftest-coverage -Wall
LDFLAGS := -lgcov --coverage
LDLIBS  := -lm

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