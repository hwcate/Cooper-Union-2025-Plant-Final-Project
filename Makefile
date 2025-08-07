<<<<<<< HEAD
CC		=  avr - gcc
CFLAGS += \
	-DF_CPU=16000000ULL \
	-O0 \
	-Wall \
	-Wextra \
	-Wpedantic \
	-g \
	-mmcu=atmega328p \
	-std=gnu11 \

.PHONY: all
all: main.elf

.PHONY: clean
clean:
	@rm -rvf *.d *.elf *.o

main.elf: main.o 
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MM -MF $*.d $<
	$(CC) $(CFLAGS) -c $<

=======
CC		= 
CFLAGS += \
	-DF_CPU=16000000ULL \
	-O0 \
	-Wall \
	-Wextra \
	-Wpedantic \
	-g \
	-mmcu=atmega328p \
	-std=gnu11 \

.PHONY: all
all: main.elf

.PHONY: clean
clean:
	@rm -rvf *.d *.elf *.o

main.elf: main.o 
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MM -MF $*.d $<
	$(CC) $(CFLAGS) -c $<

>>>>>>> a8b9e64d100345cb4de584ca01a0edf612bd0563
-include $(wildcard *.d)