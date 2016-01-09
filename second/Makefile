all: clean second

clean:
	rm -f second

%: %.c
	gcc -Wall -O3 -o $@ $<

package:
	tar -cf package.tar Makefile *.c
