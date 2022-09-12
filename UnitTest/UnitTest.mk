# Makefile for UnitTest

UNITTESTPATH 	:= UnitTest
OBJ				:= ./obj
UNITTESTSRC		:= $(UNITTESTPATH)/src

UNITTESTSOURCE = $(wildcard $(UNITTESTSRC)/*.c)

UNITESTINCLUDE 	= $(UNITTESTPATH)/include

UNITTESTOBJS 	= $(patsubst $(UNITTESTPATH)/src/%.c,$(OBJ)/%.o,$(UNITTESTSOURCE))
