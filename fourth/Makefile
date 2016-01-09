all: clean fourth

clean:
	rm -f fourth

%: %.c
	gcc -Wall -O3 -o $@ $<

package:
	tar -cf package.tar Makefile *.c
