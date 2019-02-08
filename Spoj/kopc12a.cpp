//www.spoj.com/problems/KOPC12A/

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


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

#define MAXN 100009

ll h[MAXN], c[MAXN];
int n;

ll f(ll x){

	ll ret = 0;
	fr(i, n){
		ll aux = abs(x-h[i]);
		aux *= c[i];
		ret += aux;
	}
	return ret;
}

ll ts(double l, double r) {

    while (r-l > 3) {
        ll m1 = l + (r-l) / 3;
        ll m2 = r - (r-l) / 3;
        ll f1 = f(m1);   
        ll f2 = f(m2);     
        if (f1 > f2) 
            l = m1;
        else if (f2 > f1)
            r = m2;
        else
        	l = r;
    }
    ll ret = LLONG_MAX;
    for (int i = l; i <= r; i++){
    	ret = min(ret, f(i));
    }   

    return ret;
}

int main(){
	fastio

	int t;
	cin >> t;

	while (t--){
		cin >> n;

		fr(i, n) cin >> h[i];
		fr(i, n) cin >> c[i];

		cout << ts(0, 10000) << endl;
	}		
}
