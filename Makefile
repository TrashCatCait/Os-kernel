##NOTE while this does work and compile successfully if you swap to using the gnu linker ld or any other linker for that matter remove -flto from the Cflags

-include ./Makefile.var

##Compiler settings
CC=clang
ASM=nasm
LD=ld.lld

##Kernel Compile flags
CFLAGS=-Os -nostdlib -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -ffreestanding 
AFLAGS=-felf64

##Settings
BUILD=build
CSRC=$(wildcard src/*.c)
ASRC=$(wildcard src/*.asm)
ASMOBJS=$(patsubst src/%.asm, $(BUILD)/%.o, $(ASRC))
COBJS=$(patsubst src/%.c, $(BUILD)/%.o, $(CSRC))

$(KENTARGET): $(BUILD) $(COBJS) $(ASMOBJS)
	$(LD) --nostdlib -T./kernel.ld -o $@ 

./$(BUILD)/%.o: ./src/%.asm
	$(ASM) $(AFLAGS) $^ -o $@

./$(BUILD)/%.o: ./src/%.c 
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD):
	mkdir -vp $@

##Debug options:
##Basic error checking
.PHONY: clean check strictcheck fullcheck

##we don't check cpp guidelines as we are using base C and not cpp
##we don't use magic numbers check as that just reports all numbers that have been used.
##header guards are disabled as the fixes suggested casued another error
##altera-struct-pack is disabled as it suggests fixes that will actually break things i.e. changing packed stuctures to unpacked and aligned. However I will use this to align structures where packed isn't required
check:
	clang-tidy  -checks="*,-clang-analyzer-cplusplus*,-cppcoreguidelines*,-readability-magic-numbers,-llvm-header-guard,-altera-struct-pack-align" src/*.c -- -DDEBUG -Isrc/includes
	clang-tidy  -checks="*,-clang-analyzer-cplusplus*,-cppcoreguidelines*,-readability-magic-numbers,-llvm-header-guard,-altera-struct-pack-align" src/includes/*.h -- -DDEBUG -Isrc/includes

##More strict check that checks structures packing aswell. This is disdabled by default are there are some false postives such as GDT,IDT,etc...
strictcheck:
	##Only checks the .c files as the asm files would likely produce false postive errors
	clang-tidy  -checks="*,-clang-analyzer-cplusplus*,-cppcoreguidelines*,-llvm-header-guard,-readability-magic-numbers" src/*.c -- -DDEBUG -Isrc/includes
	clang-tidy  -checks="*,-clang-analyzer-cplusplus*,-cppcoreguidelines*,-llvm-header-guard,-readability-magic-numbers" src/includes/*.h -- -DDEBUG -Isrc/includes

##Full and complete check with clang tidy. Only cpp features disabled. Due to this project being C
fullcheck: 
	##Only checks the .c files as the asm files would likely produce false postive errors
	clang-tidy  -checks="*,-clang-analyzer-cplusplus*,-cppcoreguidelines*" src/*.c -- -DDEBUG -Isrc/includes
	clang-tidy  -checks="*,-clang-analyzer-cplusplus*,-cppcoreguidelines*" src/includes/*.h -- -DDEBUG -Isrc/includes

clean: 
	@rm -rvf *.plist $(BUILD) $(KENTARGET)
