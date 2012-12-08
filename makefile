UNAME := $(shell uname)
PROGRAM :=PONG
ifeq ($(UNAME), Darwin)

all:
	@echo "Found Darwin System"
	gcc -o $(PROGRAM) -I/Library/Frameworks/SDL.framework/Headers *.c SDLmain.m -framework SDL -framework Cocoa 
endif


ifeq ($(UNAME), Linux)
all:
	@echo "Found Linux System"
	gcc -o $(PROGRAM) -I/usr/include/SDL -lSDL *.c 
endif

