# Makefile contributed by jtsiomb

src = os.asm

main = main.c

.PHONY: all
all: os.img build

os.img: $(src)
	nasm -f bin -l os.lst -o $@ $(src)
	truncate -s 360K $@

.PHONY: clean
clean:
	$(RM) os.img
	$(RM) a.bin

.PHONY: runqemu
runqemu: os.img
	qemu-system-i386 -fda os.img

.PHONY: runqemu_ng
runqemu_ng: os.img
	qemu-system-i386 -fda os.img --nographic

build: $(main)
	smlrc $(main) tmp
	echo "org 0x7C00" | cat - tmp > a.asm
	$(RM) tmp
	nasm a.asm -o a.bin
