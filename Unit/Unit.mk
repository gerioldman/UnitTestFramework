# Makefile for Unit

UNITPATH 		:= Unit
OBJ				:= ./obj
PRE				:= ./pre
UNITSRC		:= $(UNITPATH)/src

# List of source files
UNITSOURCE 	= $(wildcard $(UNITSRC)/*.c)

# Include folder
UNITINCLUDE = $(UNITPATH)/include

# List of object files 
UNITOBJS 	= $(patsubst $(UNITPATH)/src/%.c,$(OBJ)/%.o,$(UNITSOURCE))

# List of preprocessed source files for automatic unit stub generation
UNITPREPARE = $(patsubst $(UNITPATH)/src/%.c,$(PRE)/%.i,$(UNITSOURCE))