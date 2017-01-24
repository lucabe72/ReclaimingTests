CFLAGS=-Wall -Wextra
CPPFLAGS=-Ilibdl

test: chdl/chdl hog test.sh
	sh test.sh

chdl/chdl:
	make -C chdl

hog: hog.o

clean:
	rm -f hog hog.o
	make -C chdl clean
