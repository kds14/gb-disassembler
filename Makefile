all: gbdis.c
	@mkdir -p build
	gcc gbdis.c -o ./build/gbdis

clean:
	rm -r ./build
