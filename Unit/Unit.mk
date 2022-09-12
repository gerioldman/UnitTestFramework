# Makefile for Unit

UNITPATH 		:= Unit
OBJ				:= ./obj
UNITSRC		:= $(UNITPATH)/src

UNITSOURCE 	= $(wildcard $(UNITSRC)/*.c)

UNITINCLUDE = $(UNITPATH)/include

UNITOBJS 	= $(patsubst $(UNITPATH)/src/%.c,$(OBJ)/%.o,$(UNITSOURCE))