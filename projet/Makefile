C=gcc
CFLAGS=-Wall
LIBS = -L./SDL2_ttf/.libs -L./SDL2_image/.libs
LDFLAGS= `sdl2-config --cflags --libs`
INCLUDES= -I./SDL2_ttf -I./SDL2_image
EXEC=main
SRC= main.c graphic.c niveau.c pacman.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)

%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $<
clean:
		rm -rf *.o *~
mrproper: clean
		rm -rf $(EXEC)
