UNITTESTRUNNERPATH 		:= UnitTestRunner
OBJ						:= ./obj
PRE   					:= ./pre
UNITTESTRUNNERSRC		:= $(UNITTESTRUNNERPATH)/src

UNITTESTRUNNERSOURCE 	= $(wildcard $(UNITTESTRUNNERSRC)/*.c)

UNITESTRUNNERINCLUDE 	= $(UNITTESTRUNNERPATH)/include

UNITTESTRUNNEROBJS 		= $(patsubst $(UNITTESTRUNNERSRC)/%.c,$(OBJ)/%.o,$(UNITTESTRUNNERSOURCE))
