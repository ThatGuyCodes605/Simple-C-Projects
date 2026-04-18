CC     = gcc
CFLAGS = -Wall -Wextra -Iinclude
LIBS   = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
GLAD   = src/glad.c

opengl%: opengl%.c
	$(CC) $(CFLAGS) $< $(GLAD) -o $@ $(LIBS)

clean:
	rm -f opengl[0-9]*