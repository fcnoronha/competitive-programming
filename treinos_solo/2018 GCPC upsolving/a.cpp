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

#define maxn 1090
#define maxl 25

ll h, w, cnt, id[maxn][maxn], dist[maxn*maxn], vis[maxn*maxn];
vl adj[maxn*maxn], adj2[maxn*maxn];

int timer;
int tin[maxn*maxn], tout[maxn*maxn];
int up[maxn*maxn][maxl];

void dfs(int v, int p) {

    tin[v] = ++timer;
    up[v][0] = p;
    
    for (int i = 1; i < maxl; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = maxl-1; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

//// REST ////

void bfs(int r) {

    queue<int> q;
    q.push(r);
    
    while (!q.empty()) {

        int v = q.front();
        q.pop();

        vis[v] = 1;

        for (auto u: adj2[v]) {
            
            if (vis[u]) continue;
            
            adj[v].pb(u);
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }

    dfs(r, r);
}

ll calc(int from, int to) {

    int l = lca(from, to);
    
    ll ret = ll(dist[from]) + ll(dist[to]) - 2ll*ll(dist[l]);
    return ret;
}

void oi() {

    frr(i, h) {
        frr(j, w) {

            int oi = id[i][j];
            cout << dist[oi] << " ";
        }
        cout << endl;
    }
}

int main(){
    fastio;

    cin >> h >> w;

    frr(i, h) frr(j, w) id[i][j] = cnt++;
    cnt--;

    string s;

    int ri = 1;
    fr(i, h+1) {

        string s;
        cin >> ws;
        getline(cin, s);
        
        if (!i) continue;

        int rj = 1;
        for (int j = 1; j <= 2*w+1; j += 2) {

            int act = id[ri][rj];

            if (rj < w && s[j+1] == ' ') {
                
                int right = id[ri][rj+1];

                adj2[right].pb(act);
                adj2[act].pb(right);
            }

            if (ri < h && s[j] == ' ') {
                
                int down = id[ri+1][rj];

                adj2[down].pb(act);
                adj2[act].pb(down);
            }

            rj++;
        }

        ri++;
    }
    
    int q;
    cin >> q;

    pii lst = {-1, -1};
    ll ans = 0;
    while (q--) {

        pii act;
        cin >> act.f >> act.s;

        if (lst.f == -1) {
            lst = act;
            bfs(id[lst.f][lst.s]);
            continue;
        }

        int from = id[lst.f][lst.s];
        int to = id[act.f][act.s];
        lst = act;

        ans += calc(from, to);
    }

    cout << ans << endl;
}

