all: clean fifth

clean:
	rm -f fifth

%: %.c
	gcc -Wall -O3 -o $@ $<

package:
	tar -cf package.tar Makefile *.c
