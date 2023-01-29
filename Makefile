FLAGS := -g -std=c11 -pedantic -Wall -Wextra

all: primes primes-i steg-decode

run: primes primes-i
	./primes
	./primes-i

primes.o : primes.c
	gcc $(FLAGS) -c primes.c

primes-i.o : primes.c
	gcc $(FLAGS) -DUSE_INLINE -c -o primes-i.o primes.c

eratosthenes.o : eratosthenes.c
	gcc $(FLAGS) -c eratosthenes.c

eratosthenes-i.o : eratosthenes.c
	gcc $(FLAGS) -DUSE_INLINE -c -o eratosthenes-i.o eratosthenes.c

error.o : error.c
	gcc $(FLAGS) -c error.c

steg-decode.o : steg-decode.c
	gcc $(FLAGS) -c steg-decode.c

ppm.o : ppm.c
	gcc $(FLAGS) -c ppm.c

bitset.o : bitset.c
	gcc $(FLAGS) -c bitset.c

bitset-i.o : bitset.c
	gcc $(FLAGS) -DUSE_INLINE -c -o bitset-i.o bitset.c

primes: primes.o bitset.o eratosthenes.o error.o
	gcc $(FLAGS) -o primes primes.o bitset.o eratosthenes.o error.o -lm

primes-i: primes-i.o bitset-i.o eratosthenes-i.o error.o
	gcc $(FLAGS) -o primes-i primes-i.o bitset-i.o eratosthenes-i.o error.o -lm -O0

steg-decode: steg-decode.o ppm.o bitset.o eratosthenes.o error.o
	gcc $(FLAGS) -o steg-decode $^ -lm

clean:
	rm -f primes primes-i steg-decode *.o