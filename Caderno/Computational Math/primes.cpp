// CHECKING IF A NUMBER IS PRIME O(n^(1/2))

bool isPrime(ll n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (ll i = 5; i*i <= n; i = i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

// GENERATE ALL PRIMES UNTIL n O(n)
vector<int> isPrime(maxn, true);
vector<int> primes;
vector<int> SPF(maxn);

void seive(int n) {

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            SPF[i] = i;
        }

        for (int j = 0;
        j < (int)primes.size() &&
        i*primes[j] < n && primes[j] <= SPF[i];
        j++) {
            isPrime[i*primes[j]] = false;
            SPF[i*primes[j]] = primes[j] ;
        }
    }

    // All generated primes will be at primes[]
    // Change types to long long if needed
}
