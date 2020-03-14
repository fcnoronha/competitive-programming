//codeforces.com/contest/1325/problem/C

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
vi adj[maxn];
map<pii, int> vals;
int clk;
int prt[maxn], dist[maxn];

void dfs(int u, int p) {

    prt[u] = p;
    for (auto v: adj[u]) 
        if (v != p) { 
            dist[v] = dist[u]+1;
            dfs(v, u); 
        }
}

int main() {
    fastio;

    int n;  
    cin >> n;
    vector<pii> e;
    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        e.pb({u,v});
        vals[{u,v}] = -1; 
    }

    dfs(1, 1);
    int mx = 1;
    frr(i, n) if (dist[i] > dist[mx]) mx = i;

    ms(dist, 0);
    dfs(mx, mx);
    int a = mx;
    clk = 0;
    frr(i, n) if (dist[i] > dist[mx]) mx = i;
    int b = mx;
    
    vals[{b, prt[b]}] = vals[{prt[b], b}] = clk++;
    b = prt[b];

    clk = n-2;

    while (b != a) {
        if (prt[b] == a) {
            vals[{b, prt[b]}] = vals[{prt[b], b}] = 1;
            break;
        }
        vals[{b, prt[b]}] = vals[{prt[b], b}] = clk--;
        b = prt[b];
    }

    for (auto x: e) {
        if (vals[x] == -1) vals[x] = clk--;
        cout << vals[x] << endl;
    }
}
