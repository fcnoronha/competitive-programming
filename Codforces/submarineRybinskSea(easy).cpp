//codeforces.com/contest/1195/problem/D1

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef unsigned long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

const ll mod = 998244353;

ll coiso(ll n, bool s) {

    ll mul = 1ll;
    if (s) mul = 10ll;

    ll ret = 0ll;
    while (n) {

        ll aux = n%10ll;
        n /= 10ll;

        ret = (ret + (aux*mul)%mod)%mod;
        mul *= 100ll;
    }

    return ret;
}

int main(){
	fastio

    int n;
    cin >> n;

    ll a[n];
    fr(i, n) cin >> a[i];

    ll k = 0ll;
    fr(i, n) {

        ll aux = coiso(a[i], 0);
        k = (k+aux)%mod;

    }

    ll ans = 0ll;
    fr(i, n) {

        ll g = coiso(a[i], 1);

        ans = (ans + (k+ (n*g)%mod)%mod)%mod;
    }

    p(ans);
}
