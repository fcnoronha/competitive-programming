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
#define pq priority_queue
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

#define maxn 11234

vi adj[maxn];
int out_deg[maxn], in_deg[maxn], lvl[maxn], par[maxn];

void dfs(int u, int h) {
    lvl[u] = h;
    for (auto v: adj[u]) dfs(v, h+1);
}

int main() {
    fastio;

    int n, t;
    cin >> n >> t;
    frr(i, n) {
        int a;
        cin >> a;
        // i -> a
        adj[a].pb(i);
        par[i] = a;
        in_deg[a]++;
        out_deg[i]++;
    }

    int ans = 0;

    pq<pii> fila;
    frr(i, n) {
		if(par[i] == 0){
			dfs(i, 0);
		}
	}

	frr(i, n){
		if(in_deg[i] == 0) fila.push(make_pair(lvl[i], i));
	}

    while (fila.empty() == 0) {

        set<int> aux;
	
		for(int i = 0; i < t && fila.empty() == 0; i++){
			aux.insert(fila.top().s);
			fila.pop();
		}

        for (auto u: aux) {
			if(par[u] == 0) continue;
            in_deg[par[u]]--;
			if(in_deg[par[u]] == 0) fila.push(make_pair(lvl[par[u]], par[u]));
        }

		ans++;
    }

    p(ans);
}