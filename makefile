UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)

all:
	gcc -o PONG -I/Library/Frameworks/SDL.framework/Headers main.c run.c ball.c SDLmain.m -framework SDL -framework Cocoa 
endif

ifeq ($(UNAME), Linux)
all:
	gcc -o PONG -lSDL main.c run.c ball.c 
endif

