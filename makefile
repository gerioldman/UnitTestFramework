include UnitTestRunner/UnitTestRunner.mk
include UnitTest/UnitTest.mk

MKDIR   := mkdir
RMDIR   := rm -rf
CC      := mingw32-gcc
BIN     := ./bin
OBJ     := ./obj
#INCLUDE := ./include
#SRC     := ./src
#SRCS    := $(wildcard $(SRC)/*.c)
#OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
OBJS    := $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS)
EXE     := $(BIN)/main.exe
CFLAGS  := -g -I$(UNITESTRUNNERINCLUDE) -I$(UNITESTINCLUDE)
LDLIBS  := -lm

.PHONY: all run clean

all: $(EXE)

$(EXE): $(UNITTESTRUNNEROBJS) $(UNITTESTOBJS) | $(BIN)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(UNITTESTRUNNEROBJS): $(OBJ)/%.o: $(UNITTESTRUNNERSRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(UNITTESTOBJS): $(OBJ)/%.o: $(UNITTESTSRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	$(MKDIR) $@

run: $(EXE)
	$<

clean:
	$(RMDIR) $(OBJ) $(BIN)