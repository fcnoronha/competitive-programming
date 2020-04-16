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

#define maxn 200009 

vi adj[maxn];
int dist[maxn], vis[maxn], par[maxn];
map<pii, char> cst;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    fr(i, m) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].pb(v);
        adj[v].pb(u);
        cst[{u,v}] = cst[{v,u}] = c;
    }

    ms(dist, INF);
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        for (auto v: adj[u]) 
            if (dist[v] > dist[u]+1) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
    }

    ms(vis, 0);
    string ans;
    vi lvl[maxn];
    lvl[0] = vi{1};
    fr(i, dist[1]) {

        pii mn = {INF, 'z'};
        for (auto u: lvl[i]) 
            for (auto v: adj[u])
                mn = min(mn, {dist[v], cst[{u,v}]});

        ans += mn.s;
        for (auto u: lvl[i]) 
            for (auto v: adj[u]) {
                if (dist[v] > mn.f || cst[{u,v}] > mn.s) continue;
                if (vis[v]) continue;
                vis[v] = 1;
                par[v] = u;
                lvl[i+1].pb(v);
            }
    }

    vi aux;
    aux.pb(n);
    int x = par[n];
    while (x != 1) {
        aux.pb(x);
        x = par[x];
    }
    aux.pb(1);
    reverse(all(aux));

    p(dist[1]);
    pv(aux);
    p(ans);
}
