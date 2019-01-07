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
vector<int> isPrime(MAXN, true); 
vector<int> prime; 
vector<int> SPF(MAXN); 
  
void seive(int n) 
{ 
  isprime[0] = isprime[1] = false; 

  for (int i = 2; i < n; i++){ 
    if (isPrime[i]){ 
        prime.push_back(i); 
        SPF[i] = i; 
    } 

    for (int j = 0; 
         j < (int)prime.size() && 
         i*prime[j] < n && prime[j] <= SPF[i]; 
         j++) 
    { 
        isPrime[i*prime[j]] = false; 
        SPF[i*prime[j]] = prime[j] ; 
    } 
  } 

  // All generated primes will be at primes[]
  // Change types to long long if needed
} 
