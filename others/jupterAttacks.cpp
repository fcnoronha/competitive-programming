//www.urionlinejudge.com.br/judge/en/problems/view/1356

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

ll b, q, n;
ll mod;
ll seg[2*maxn];
ll ans;

ll fastexp(ll base, ll exp){
	if (!exp) return 1;
	ll ans = fastexp(base, exp/2);
	ans = (ans*ans)%mod;
	if (exp%2) ans = (ans*base)%mod;
	return ans%mod; 
}

ll invmod(ll x){
	return fastexp(x, mod-2);
}

void update(int p, int val) {
    for (seg[p+=n] = val; p > 1; p >>= 1) 
        seg[p>>1] = (seg[p] + seg[p^1])%mod; 
}

ll query(int l, int r) {
    int ret = 0ll;
    for (l += n, r += n+1; l < r; r>>=1, l>>=1) {
        if (l&1) ret = (ret+seg[l++])%mod;
        if (r&1) ret = (ret+seg[--r])%mod;
    }
    return ret;
} 

int main(){
    fastio;

    while (cin >> b >> mod >> n >> q && b && mod && q && n) {

        fr(i, n) seg[i] = seg[i+n] = 0;

        char op;
        int i,j;
        ll v;
        while (q--) {

            cin >> op;
            if (op == 'E') {
                cin >> i >> v;
                i--; 
            
                v = (v*fastexp(b, n-i))%mod;
                update(i, v);
            }
            else {
                cin >> i >> j;
                i--, j--;

                ans = query(i, j);
                ll d = invmod(fastexp(b, n-j));
                ans = (ans*d)%mod;
                p(ans);
            }
        }

        p('-');
    }
}
