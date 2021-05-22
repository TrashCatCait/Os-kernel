##Compiler settings
CC=gcc
LD=ld 
##Kernel Compile flags
CFLAGS=-ffreestanding -mno-red-zone
LFLAGS=-nostdlib

./kernel.elf: build ./build/kernel.o
	$(LD) $(KLFLAGS) -T./kernel.ld -o $@ ./build/kernel.o 

./build/kernel.o: ./src/kernel.c 
	$(CC) $(KCFLAGS) -c $^ -o $@

build:
	mkdir $@

.PHONY: clean 

clean:
	rm -rf build kernel.elf
