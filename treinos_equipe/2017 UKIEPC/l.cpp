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


int lis(vi v){

	vi st; 

	for (int i = 0; i < v.size(); i++){
		auto it = lower_bound(st.begin(), st.end(), v[i]);
		if (it == st.end()) st.pb(v[i]);
		else *it = v[i];
	}

	return st.size();
}

ll dist(pll a, pll b) {
    return (a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s);
}

int main(){

    fastio;

    ll tx, ty;
    cin >> tx >> ty;

    int n;
    cin >> n;

    pll pos[n];
    int h[n];

    fr(i, n) 
        cin >> pos[i].f >> pos[i].s >> h[i];
    
    map< pll, vi > mp1, mp2;
    fr(i, n) {

        ll d1 = (ty - pos[i].s);
        ll d2 = (tx - pos[i].f);
        
        ll g = __gcd(abs(d2), abs(d1));
        d1 /= g;
        d2 /= g;

        if (d1 < 0 && d2 < 0) {
            d1 = -d1;
            d2 = -d2;
        }

        if (pos[i].f < tx) {
            mp1[{d1, d2}].pb(i);
            continue;
        } 

        if (pos[i].f == tx) {
            if (pos[i].s < ty) {
                mp1[{d1, d2}].pb(i);
                continue;
            }
        } 

        mp2[{d1, d2}].pb(i);
    }

    int ans = 0;
    for (auto x: mp1) {
     
        vi oi = x.s;
        vector< pair<double, int> > v;
        for (auto p: oi) 
            v.pb({dist(pos[p], make_pair(tx, ty)), h[p]});

        sort(all(v));

        vi aux;
        for (auto p: v) aux.pb(p.s);

        ans += lis(aux);
    }

    for (auto x: mp2) {
     
        vi oi = x.s;
        vector< pair<double, int> > v;
        for (auto p: oi) 
            v.pb({dist(pos[p], make_pair(tx, ty)), h[p]});

        sort(all(v));

        vi aux;
        for (auto p: v) aux.pb(p.s);

        ans += lis(aux);
    }

    p(ans);
}
