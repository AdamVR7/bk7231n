CC = gcc
CFLAGS = -I./sdk/include -Wall -O2
LDFLAGS = -L./sdk/lib -lgpio -lwifi -lmqtt

SRC = main.c
OBJ = $(SRC:.c=.o)

all: firmware

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

firmware: $(OBJ)
	$(CC) $(OBJ) -o firmware $(LDFLAGS)

clean:
	rm -f *.o firmware

