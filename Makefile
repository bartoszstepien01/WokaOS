CPP_COMPILER = g++
ASSEMBLY_COMPILER = nasm
LINKER = ld
CPP_FLAGS = -ffreestanding -fno-exceptions -fno-rtti -m32
ASSEMBLY_FLAGS = -f elf32
LINKER_FLAGS = -m elf_i386 -T linker.ld
EMULATOR = qemu-system-i386
OUTPUT_FOLDER = output/

all: compile_assembly compile_cpp linker emulate

compile_assembly:
ifeq ("$(wildcard $(OUTPUT_FOLDER)/loader.o)","")
	$(ASSEMBLY_COMPILER) $(ASSEMBLY_FLAGS) loader.asm -o $(OUTPUT_FOLDER)loader.o
endif

compile_cpp:
	$(CPP_COMPILER) -c kernel.cpp -o $(OUTPUT_FOLDER)kernel.o $(CPP_FLAGS)

linker:
	$(LINKER) $(LINKER_FLAGS) -o $(OUTPUT_FOLDER)kernel.bin $(OUTPUT_FOLDER)loader.o $(OUTPUT_FOLDER)kernel.o

emulate:
	$(EMULATOR) -kernel $(OUTPUT_FOLDER)kernel.bin -soundhw pcspk