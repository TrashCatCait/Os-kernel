##NOTE while this does work and compile successfully if you swap to using the gnu linker ld or any other linker for that matter remove -flto from the Cflags

-include ./Makefile.var

##Compiler settings
CC=clang
ASM=nasm
LD=ld.lld

##Kernel Compile flags
CFLAGS=-nostdlib -O3 -flto -ffreestanding 
LFLAGS=--nostdlib
AFLAGS=-felf64

##Settings
BUILD=build
CSRC=$(wildcard src/*.c)
ASRC=$(wildcard src/*.asm)
ASMOBJS=$(patsubst src/%.asm, $(BUILD)/%.o, $(ASRC))
COBJS=$(patsubst src/%.c, $(BUILD)/%.o, $(CSRC))

$(KENTARGET): $(BUILD) $(COBJS) $(ASMOBJS)
	$(LD) $(LFLAGS) -T./kernel.ld -o $@ $(COBJS) $(ASMOBJS) 

./$(BUILD)/%.o: ./src/%.asm
	$(ASM) $(AFLAGS) $^ -o $@

./$(BUILD)/%.o: ./src/%.c 
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD):
	mkdir -vp $@

.PHONY: clean 
clean:
	@rm -rvf $(BUILD) $(KENTARGET)
