#include <iostream>
using namespace std;
/*
	Write an assembler subroutine to calculate eratosthenes' sieve.
	You are counting the number of primes from 2 to n.
	First set all bits to 1 (you can do this 32 bits at a time by setting
	each word to 0xFFFFFFFF)
	Then for each prime (for example 2) clear all multiples of that number. (125Mb)
	2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
  1 1 0 1 0 1 0 0 0   1  0  1  0  1  0  1  0  1  0  1


50% bonus for storing only odd numbers (62.5Mb)
	  3 5 7 9 11 13 15 17 19 21
  0 1 2 3 4 5  6   7  8 9  10
  right shift by 1 divides by 2 and discards the odd number!


	pseudocode
  for i = 2 to n
    isPrimes[i] = true
  end

	for i = 4 to n step 2
	  isPrime[i] = false   (4, 6, 8, ... not prime)
  end

  count = 1  // special case: 2 is prime
	for i = 3 to n step 2
	  if isPrime[i]
      count = count + 1
      for j = i*i to n step i*2
        isPrime[j] = false
    end
  end
 */

extern uint32_t era(uint32_t* array, uint32_t n); //tosthenes

int main() {
	uint32_t n = 1000000000;
	uint32_t* sieve = new uint32_t[(n+31)/32];
	uint32_t count = era(sieve, n);
	cout << "Primes up to " << n << " = " << count << '\n';
	delete [] sieve;
}
