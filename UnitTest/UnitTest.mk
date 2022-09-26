# Makefile for UnitTest

UNITTESTPATH 	:= UnitTest
OBJ				:= ./obj
UNITTESTSRC		:= $(UNITTESTPATH)/src

UNITTESTSOURCE = $(wildcard $(UNITTESTSRC)/*.c)

UNITESTINCLUDE 	= $(UNITTESTPATH)/include

UNITTESTOBJS 	= $(patsubst $(UNITTESTPATH)/src/%.c,$(OBJ)/%.o,$(UNITTESTSOURCE))

UNITTESTSTUBSRC = $(UNITTESTPATH)/stubs

UNITTESTSTUBSOURCE = $(wildcard $(UNITTESTSTUBSRC)/*.c)

UNITTESTSTUBOBJS = $(patsubst $(UNITTESTSTUBSRC)/%.c,$(OBJ)/%.o,$(UNITTESTSTUBSOURCE))

UNITTESTSTUBINCLUDE = $(UNITTESTPATH)/include/stubs
