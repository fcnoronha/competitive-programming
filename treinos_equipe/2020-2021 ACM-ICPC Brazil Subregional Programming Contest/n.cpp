#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%lld%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 
#define tsts(t) rvr(t); while(t--)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MAX_SIEVE = 5e7 + 1;
const int N = 1e3 + 1;
vector<int> prim;
int mark[MAX_SIEVE];

vii adj[N];

ll fastxp(ll x, ll n){
	ll ret = 1;
	while(n){
		if(n&1ll) ret *= x;
		x *= x;
		n /= 2ll;
	}
	return ret;
}
	
void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) prim.pb(i);
		for(int p: prim){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}

int main(){
    crivo();
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    vll vec(n);
    fr(i, n) scanf("%lld", &vec[i]);
    fr(i, k){
        int M, N, D; scanf("%d%d%d", &M, &N, &D);
        M--;
        N--;
        adj[M].pb(mp(N, D));
    }
    vll ans;
    int pos = 0, j = 0, sz = prim.size();
    while(pos < m){
        //printf("pos %d prim %d\n", pos, prim[j]);
        bool deu = true;
        if(j >= sz){
            ll mn = 1e16;
            for(auto p: adj[pos]){
                if(vec[p.ff] > 1){
                    mn = min(mn, vec[p.ff]);
                }
            }
            ans.pb(mn);
            for(auto p: adj[pos]){
                vec[p.ff] /= mn;
            } 
            pos++;
            continue;
        }
        for(auto p: adj[pos]){
            if(vec[p.ff]%fastxp(prim[j], p.ss) != 0){
                deu = false;
                break;
            }
        }
        if(deu){
            ans.pb(prim[j]);
            for(auto p: adj[pos]){
                vec[p.ff] /= fastxp(prim[j], p.ss);
            } 
            pos++;
        }
        j++;
    }
    vp(ans);
}
