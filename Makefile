CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m3 -mthumb -O2 -Wall -I./include
LDFLAGS = -T link.ld

SRC = main.c system.c
OBJ = $(SRC:.c=.o)

all: firmware.elf firmware.bin

firmware.elf: $(OBJ)
    $(CC) $(CFLAGS) $(OBJ) -o firmware.elf $(LDFLAGS)

firmware.bin: firmware.elf
    $(OBJCOPY) -O binary firmware.elf firmware.bin

clean:
    rm -f *.o firmware.elf firmware.bin
