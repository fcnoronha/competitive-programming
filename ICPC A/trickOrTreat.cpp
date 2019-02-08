// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3349

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

#define MAXN 50009

int n;
pair<ld, ld> pos[MAXN];

ld fun(ld x){
	ld ret = 0.0;
	fr(i, n)
		ret = max((ld)sqrt( (pos[i].f-x)*(pos[i].f-x) + (pos[i].s*pos[i].s) ), ret);
	return ret;
}

ld ts(ld l, ld r) {

    ld eps = 1e-12;

    while (r - l > eps) {
        ld m1 = l + (r-l) / 3;
        ld m2 = r - (r-l) / 3;
        ld f1 = fun(m1);   
        ld f2 = fun(m2);     
        if (f1 > f2) 
            l = m1;
        else
            r = m2;
    }
    return (l+r)/2;   
}

int main(){
	fastio
	
	while (cin >> n && n){

		fr(i, n) cin >> pos[i].f >> pos[i].s;

		ld aux = ts(-2000001.0, 2000001.0);
		cout << fixed << setprecision(12) << aux << " " << fun(aux) << endl;
	}
}
