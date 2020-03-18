//codeforces.com/problemset/problem/474/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 100009
const ll mod = 1000000007;

ll memo[maxn], ac[maxn];

int main() {
    fastio;

    ll t, k;
    cin >> t >> k;

    memo[0] = 1;
    frr(i, 100000) {
        memo[i] = memo[i-1];
        if (i >= k) memo[i] += memo[i-k];
        memo[i] %= mod;
    }

    frr(i, 100000) ac[i] = (memo[i] + ac[i-1])%mod;
    while (t--) {
        int a, b;
        cin >> a >> b;
        p((ac[b]-ac[a-1]+mod)%mod);
    }   
}
