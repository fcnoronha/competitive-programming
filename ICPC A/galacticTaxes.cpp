// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4898

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

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ld,ld> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define MAXN 1009

int n, m;
vector< pair<ll, pll> > adj[MAXN]; // ajd[u] = {v, {a, b}};

ld fun(ld x){
	
    bool visited[n+2];
    ld dist[n+2];

    frr(i, n) dist[i] = 1e13;
    ms(visited, 0);

    set< pair<ld, ll> > q;
    q.insert({0, 1ll});
    dist[1] = 0.0;

    while (!q.empty()){
        ll v = (*(q.begin())).s;
        q.erase(q.begin());

        if (visited[v]) continue;
        visited[v] = 1;

        for (auto u : adj[v]){

            ll ver = u.f;
            pll val = u.s;

            ld w = (val.f*x) + (ld)val.s;
            if (dist[ver] > dist[v]+w){
                dist[ver] = dist[v]+w;
                q.insert({dist[ver], ver});
            }   
        }
    }
    return dist[n];
}

// Ternary search function
ld ts(ld l, ld r) {

    fr(i, 90) {
        ld m1 = l + (r-l) / 3;
        ld m2 = r - (r-l) / 3;
        ld f1 = fun(m1);   
        ld f2 = fun(m2);     
        if (f1 < f2) // Finds maximum 
            l = m1;
        else
            r = m2;
    }

    return (l+r)/2;   
}

int main(){
	fastio
	
	while (cin >> n >> m && n != EOF){

        frr(i, n) adj[i].clear();

        fr(h, m){
            ll i, j, a, b;
            cin >> i >> j >> a >> b;

            adj[i].pb({j, {a,b}});
            adj[j].pb({i, {a,b}});
        }
		
        cout << fixed << setprecision(5) << fun(ts(0, 1440)) << endl;
	}
}
