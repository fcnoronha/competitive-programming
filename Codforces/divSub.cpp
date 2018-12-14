// codeforces.com/contest/1076/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<long long> isprime(1000000, true); 
vector<long long> prime; 
vector<long long> SPF(1000000); 
  
void manipulated_seive() 
{ 
	int N = 1000000;
    isprime[0] = isprime[1] = false ; 
  
    for (long long int i=2; i<N ; i++) 
    { 
        if (isprime[i]) 
        { 
            prime.push_back(i); 

            SPF[i] = i; 
        } 

        for (long long int j=0; 
             j < (int)prime.size() && 
             i*prime[j] < N && prime[j] <= SPF[i]; 
             j++) 
        { 
            isprime[i*prime[j]]=false; 
            SPF[i*prime[j]] = prime[j] ; 
        } 
    } 
} 
 

int main(){
	manipulated_seive();

	ll n;
	cin >> n;

	prime.pb(n);

	ll ans = 0;
	while (n%2 != 0){
		bool roda = 1;
		for (int u = 0; u < prime.size() && roda; u++)
			if (n%prime[u] == 0)
				n -= prime[u], roda = 0, ans++;
	}

	ans += n/2;

	cout << ans << endl;
}
