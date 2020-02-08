// EULER TOTIENT

// Calculate number of numbers N that are lower than X and gcd(X, Ni) = 1.

// O(sqrt(X))

typedef long double ld;

int euler(int x){

	ld aux = (ld(n));

	for (ll p = 2; p*p <= n; p++){

		// Using the fact the N is a product of powers of primes to
		// make the answer
		if (n%p == 0){
			while (n%p == 0) n /= p;
			aux *= (1.0 - (1.0/(ld)p));
		}
	}

	// If n>1, n is prime
	if (n > 1){
		aux *= (1.0 - (1.0/ld(n)));
	}

	ans = (int)aux;
	return ans;
} 