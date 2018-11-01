// Checking with O(n^(1/2))

bool isPrime(ll n){ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i = 5; i*i <= n; i = i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

// Checking if a number in the form (2^p + 1) is prime
bool isPrime(ll p) { 
  
  ll check = fastExp(2, p) - 1; 

  ll nextval = 4 % check; 
  
  for (int i = 1; i < p - 1; i++)  
    nextval = (nextval * nextval - 2) % check;   
    
  return (nextval == 0); 
} 
