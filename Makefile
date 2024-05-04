CC := gcc

CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lSDL2_ttf -lm -O3 -ffast-math -march=native
HDRS :=

SRCS := main.c gamelogic.c mgfx.c

OBJS = $(SRCS:.c=.o)

EXEC := bees

all: $(EXEC)

main: main.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

gamelogic: gamelogic.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

mgfx: mgfx.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
