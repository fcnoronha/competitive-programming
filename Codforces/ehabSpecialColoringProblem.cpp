//codeforces.com/contest/1174/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define maxn 100009

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


int main(){
	fastio

    int n;
    cin >> n;

    int on = n+3;

    // First, I need to generate all prime numbers until N
    seive(n+1);

    int cnt = 1;
    vi ans(n+2, 0);

    // Giving each position with prime index a diferent number
    for (auto p : primes)
        ans[p] = cnt++;

    // For each number that is not prime, I assign the value associated with
    // the first prime number wich is divisor of it
    for (int i = 2; i <= n; i++) {

        if (ans[i] != 0) continue;

        int d;
        for (auto x : primes)
            if (i%x == 0) {
                d = x;
                break;
            }

        ans[i] = ans[d];
    }

    for (int i = 2; i <= n; i++)
        cout << ans[i] << " ";

    p("");
}
