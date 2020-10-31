# simple makefile to compile in the same way as the judge that runs
# g++ -g -O2 -std=gnu++17 -static
# and perform more checks

CC=g++
CFLAGS=-g -O2 -std=c++17
WFLAGS=-Wall -Wextra -Wshadow -pedantic -fsanitize=address -fsanitize=undefined -fno-sanitize-recover 

.cpp:
	$(CC) $(CFLAGS) $(WFLAGS) -o $@ $< 

clean:
	rm ?