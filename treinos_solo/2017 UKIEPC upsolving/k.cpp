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

#define maxn 101

int n, m;
int mxl[maxn], wg[maxn], tw[maxn];
int in[maxn], out[maxn], idt[maxn];
vi ans;

struct FlowEdge {
    int u, v;
    ll cap, flow = 0;
    int type;
};

vector<FlowEdge> edges;
vector<vi> adj;
vi level, ptr;
queue<int> q;
int cnt; 
 
void init(int n) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
}
 
void add_edge(int u, int v, ll cap, int type) {
    edges.pb({u, v, cap, 0, type});
    edges.pb({v, u, 0ll, 0, type});
    adj[u].pb(cnt++);
    adj[v].pb(cnt++);
}
 
bool bfs(int t) {
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int id : adj[u]) {
            if (edges[id].cap - edges[id].flow < 1)
                continue;
            if (level[edges[id].v] != -1)
                continue;
            level[edges[id].v] = level[u] + 1;
            q.push(edges[id].v);
        }
    }
    return level[t] != -1;
}
 
ll dfs(int u, ll pushed, int t) {
    if (pushed == 0)
        return 0ll;
    if (u == t)
        return pushed;
    for (int& cid = ptr[u]; cid < adj[u].size(); cid++) {
        int id = adj[u][cid];
        int v = edges[id].v;
        if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
            continue;
        ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow), t);
        if (tr == 0)
            continue;
        edges[id].flow += tr;
        edges[id^1].flow -= tr;
        return tr;
    }
    return 0;
}

void dfss(int u, int p) {

    for (int cid = 0; cid < adj[u].size(); cid++) {

        int id = adj[u][cid];
        auto e = edges[id];

        int v = e.v;

        if (v == p) continue;
        if (e.flow == 0) continue;

        if (e.type != -1) {
            ans.pb(e.type);
            if (wg[e.type-1] == 0) return;
        }

        dfss(v, u);
        return;
    }
}
 
ll dinic(int s, int t) {
    ll f = 0;
    while (true) {
        fill(all(level), -1);
        level[s] = 0;
        q.push(s);
        if (!bfs(t)) break;
        fill(all(ptr), 0);
        while (ll pushed = dfs(s, LINF, t)) 
            f += pushed;
    }
    return f;
}

int main(){
    fastio;

    cin >> n;
    fr(i, n) cin >> wg[i] >> mxl[i];
    cin >> m;
    fr(i, m) cin >> tw[i];

    init(2000);

    int clk = 2, so = 0, si = 1;

    // dobrando nos
    fr(i, n) {
        in[i] = clk++;
        out[i] = clk++;
        add_edge(in[i], out[i], 1, i+1);
    }

    // torres para sink
    fr(i, m) {
        idt[i] = clk++;
        add_edge(idt[i], si, 1, -1);
    }

    // source para cranes
    fr(i, n) {
        if (wg[i]) continue;
        add_edge(so, in[i], 1, -1);
    }

    fr(i, n) {
        // cranes to cranes
        fr(j, n) {
            if (j == i) continue;
            if (wg[j] > mxl[i]) continue;
            add_edge(out[i], in[j], 1, -1);
        }
        // cranes to towers
        fr(j, m) {
            if (tw[j] > mxl[i]) continue;
            add_edge(out[i], idt[j], 1, -1);
        }
    }

    int flow = dinic(so, si);

    if (flow < m) {
        p("impossible");
        return 0;
    }

    fr(j, m) {

        ans.clear();
        dfss(idt[j], si);

        for (int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
        cout << endl;
    }
}
