#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(iii, x.size()) cout << x[iii] << " \n"[iii==x.size()-1]
#define pvv(x, n) for(int iii = 1, vaca = nnn; i <= nnn;i++) cout << x[i] << " \n"[iii==nnn];

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
const int MAX_SIEVE = 1e7 + 1;

vector<int> prim;
int mark[MAX_SIEVE];

void crivo(){
    mark[1] = 1;
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
    fastio;
    crivo();
    int n; cin >> n;
    fr(i, n){
        string a, b; cin >> a >> b;
        bool pfind = false;
        int p = 0, q = 0, cnt = 0;
        fr(j, a.size()){
            if(a[j] == '.') pfind = true;
            else if(!pfind){
                p *= 10;
                p += a[j] - '0';
            }
            else{
                p *= 10;
                p += a[j] - '0';
                cnt++;
            }
        }
        pfind = false;
        int cnt2 = 0;
        fr(j, b.size()){
            if(b[j] == '.') pfind = true;
            else if(!pfind){
                q *= 10;
                q += b[j] - '0';
            }
            else{
                q *= 10;
                q += b[j] - '0';
                cnt2++;
            }
        }
        while(cnt2 < cnt) q *= 10, cnt2++;
        while(cnt < cnt2) p *= 10, cnt++;
        int g = __gcd(p, q);
        p /= g;
        q /= g;
        if((p >= MAX_SIEVE || !mark[p]) && (q >= MAX_SIEVE || !mark[q])) cout << p << " " << q << endl;
        else if(p == q) cout << 2 << " " << 2 << endl;
        else cout << "impossible\n";
    }
}
