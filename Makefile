all: gbdis.c
	@mkdir -p build
	gcc gbdis.c header.c opcodes.c -g -I. -o ./build/gbdis

clean:
	rm -r ./build
