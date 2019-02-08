// codeforces.com/problemset/problem/578/C

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

#define MAXN 200009

int n;
pair<ld, ld> v[MAXN];

ld fun(ld x){

    ld eps = 1e-9;
    ld msf = LDBL_MIN, meh = 0;
	
    fr(i, n){
        meh = meh + (v[i].f-x);
        if (meh > msf)
            msf = meh;

        if (meh < eps)
            meh = 0;
    }

    ld aux = msf;

    msf = LDBL_MIN, meh = 0;
    
    fr(i, n){
        meh = meh + (v[i].s+x);
        if (meh > msf)
            msf = meh;

        if (meh < eps)
            meh = 0;
    }
    return max(abs(aux), abs(msf));
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
    return fun((l+r)/2);   
}

int main(){
	fastio
	
    cin >> n;

	fr(i, n) cin >> v[i].f, v[i].s = -v[i].f;

    cout << fixed << setprecision(9) << ts(-1e5, 1e5) << endl;	
}
