all: clean third

clean:
	rm -f third

%: %.c
	gcc -Wall -O3 -o $@ $<

package:
	tar -cf package.tar Makefile *.c
