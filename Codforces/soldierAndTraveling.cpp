//codeforces.com/problemset/problem/546/E?locale=en

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

struct FlowEdge {
    int u, v, tu, tv;
    ll cap, flow = 0LL;
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
 
void add_edge(int u, int v, int tu, int tv, ll cap) {
    edges.pb({u, v, tu, tv, cap, 0});
    adj[u].pb(cnt++);
    edges.pb({v, u, tv, tu, 0LL, 0});
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

    int n, m;
    cin >> n >> m;

    init(10*n);
    int aux = 1, in[n+10], out[n+10];

    frr(i, n) {
        in[i] = aux++;
        out[i] = aux++;

        add_edge(in[i], out[i], i, i, INF);
    }

    int s = aux++;
    int t = aux++;
    int sma = 0, smb = 0;

    int c;
    frr(i, n) {
        cin >> c;
        add_edge(s, in[i], -1, i, c);
        sma += c;
    }
    frr(i, n) {
        cin >> c;
        add_edge(out[i], t, i, -1, c);
        smb += c;
    }

    int u, v;
    fr(i, m) {
        cin >> u >> v;
        add_edge(in[u], out[v], u, v, INF);
        add_edge(in[v], out[u], v, u, INF);
    }

    if (dinic(s, t) != smb || smb != sma) {
        p("NO");
        return 0;
    }

    int ans[n+1][n+1];
    ms(ans, -1);

    p("YES");
    for (auto e: edges) {
            if (e.flow < 0) continue;
            if (e.tv == -1 || e.tu == -1) continue;
            if (ans[e.tu][e.tv] > 0) continue;
            ans[e.tu][e.tv] = e.flow;
        }
    
    frr(i, n) {
        frr(j, n) {
            if (ans[i][j] == -1) ans[i][j] = 0;
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }   
    
}
