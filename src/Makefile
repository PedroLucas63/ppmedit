CC = g++
CFLAGS = -Wall -g
INCLUDES = -I.
LIBS = -lm

PROG_NAME = polaroid
SRCS = main.cpp font.cpp glyph.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(PROG_NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PROG_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBS)

@PHONY: clean

clean:
	rm -f *.o *.exe $(PROG_NAME)