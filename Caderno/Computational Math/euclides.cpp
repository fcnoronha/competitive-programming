// EUCLID ALGO

// Greatest common divisor
int gcd(int a, int b){
  return (b == 0 ? a : gcd(b, a%b));
}

// Greatest common multiplier
int gcm(int a, int b){
	return (a*b)/gcd(a,b);
}

// O(log(min(a,b)))