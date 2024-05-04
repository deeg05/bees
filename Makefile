CC := gcc

CFLAGS := `pkg-config --cflags --libs --static sdl2 SDL2_image SDL2_ttf` -O3 -Ofast -lm -lSDL2_image -lSDL2_ttf
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
