-include ./Makefile.var

##Compiler settings
CC=clang
LD=ld.lld

##Kernel Compile flags
CFLAGS=--nostdlib -flto -ffreestanding -mno-red-zone
LFLAGS=-nostdlib 
BUILD=build
CSRC=$(wildcard src/*.c)
OFILES=$(patsubst src/%.c, $(BUILD)/%.o, $(CSRC))

$(KENTARGET): $(BUILD) $(OFILES)
	$(LD) $(KLFLAGS) -T./kernel.ld -o $@ $(OFILES) 

./$(BUILD)/%.o: ./src/%.c 
	$(CC) $(KCFLAGS) -c $^ -o $@

$(BUILD):
	mkdir $@

.PHONY: clean 
clean:
	@rm -rf $(BUILD) $(KENTARGET)
