//codeforces.com/contest/1474/problem/B

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 10000009

vector<ll> isPrime(maxn, true);
vector<ll> primes;
vector<ll> SPF(maxn);

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
            j++) 
        {
            isPrime[i*primes[j]] = false;
            SPF[i*primes[j]] = primes[j] ;
        }
    }
    // All generated primes will be at primes[]
    // Change types to long long if needed
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    seive(10000000);

    ll t; cin >> t;
    while (t--) {
        ll d; cin >> d;

        ll a = -1, b;
        for (auto x: primes) {
            if (a == -1 && x > d) {
                a = x;
                continue;
            }
            if (a != -1 && x-a >= d) {
                b = x;
                break;
            }
        }

        ll ans = a*b;
        for (auto x: primes) {
            if (x > d) {
                ans = min(ans, x*x*x);
                break;
            }
        }

        p(ans);
    }
}
