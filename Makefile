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

##Debug options:
##Basic error checking
.PHONY: clean check strictcheck

check:
	clang-tidy  -checks="*,-clang-analyzer-cplusplus*,-cppcoreguidelines*,-readability-magic-numbers,-llvm-header-guard,-altera-struct-pack-align" src/*.c -- -DDEBUG -Isrc/includes
	clang-tidy  -checks="*,-clang-analyzer-cplusplus*,-cppcoreguidelines*,-readability-magic-numbers,-llvm-header-guard,-altera-struct-pack-align" src/includes/*.h -- -DDEBUG -Isrc/includes

##This is a more strict check. That not all warnings actually have to be changed such as some of the magic numbers 
strictcheck:
	##Only checks the .c files as the asm files would likely produce false postive errors
	clang-tidy  -checks="*,-clang-analyzer-cplusplus*,-cppcoreguidelines*" src/*.c -- -DDEBUG -Isrc/includes
	clang-tidy  -checks="*,-clang-analyzer-cplusplus*,-cppcoreguidelines*" src/includes/*.h -- -DDEBUG -Isrc/includes

clean: 
	@rm -rvf *.plist $(BUILD) $(KENTARGET)
