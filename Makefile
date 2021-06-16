-include ./Makefile.var

##Compiler settings
CC=gcc
LD=ld 

##Kernel Compile flags
CFLAGS=-ffreestanding -mno-red-zone
LFLAGS=-nostdlib
BUILD=build


$(KENTARGET): $(BUILD) ./$(BUILD)/kernel.o
	$(LD) $(KLFLAGS) -T./kernel.ld -o $@ ./$(BUILD)/kernel.o 

./$(BUILD)/kernel.o: ./src/kernel.c 
	$(CC) $(KCFLAGS) -c $^ -o $@

$(BUILD):
	mkdir $@

.PHONY: clean 

clean:
	rm -rf build $(KENTARGET)
