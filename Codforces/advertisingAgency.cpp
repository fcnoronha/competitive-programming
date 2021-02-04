//codeforces.com/contest/1475/problem/E

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

const ll mod = 1e9+7; // To be defined

// Calculates factorial of a number
ll fat(ll x){
	if (x == 0) return 1;
	return x*fat(x-1)%mod;
}

// Recursive fastexp
ll fastexp(ll b, ll e){
	if (!e) return 1;
	ll ans = fastexp(b, e/2);
	ans = (ans*ans)%mod;
	if (e%2) ans = (ans*b)%mod;
	return ans;
}

// For you to devide a number that is in a modulo(%)
ll invmod(ll b){
	return fastexp(b, mod-2);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vi v(n);
        fr(i, n) cin >> v[i];

        sort(all(v)); reverse(all(v));

        int tgt = v[k-1], cho = 0, hav = 0;
        fr(i, n) {
            
            if (v[i] == tgt) {
                hav++;
                cho += (k!=0);
            }

            if (k) k--;
        }

        ll ans = (fat(hav) * invmod((fat(cho)*fat(hav-cho))%mod))%mod;
        p(ans);
    }
}
