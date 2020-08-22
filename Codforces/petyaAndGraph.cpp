//codeforces.com/contest/1082/problem/G

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

/*
 * Dinic's Algorithm - O(EV^2) 
 * Matching - O(E*sqrt(V))
 */
 
struct FlowEdge {
    int u, v;
    ll cap, flow = 0;
    FlowEdge(int u, int v, ll cap, ll flow = 0)
        : u(u), v(v), cap(cap), flow(flow){}
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

void uninit() {
    edges.clear();
    adj.clear();
    level.clear();
    ptr.clear();
    cnt = 0; 
}
 
void add_edge(int u, int v, ll cap) {
    edges.pb({u, v, cap});
    edges.pb({v, u, 0ll});
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
    if (!pushed) return 0ll;
    if (u == t) return pushed;
    for (int &cid = ptr[u]; cid < adj[u].size(); cid++) {
        int id = adj[u][cid];
        int v = edges[id].v;
        ll lft = edges[id].cap - edges[id].flow;
        if (level[u] + 1 != level[v] || lft < 1)
            continue;
        ll tr = dfs(v, min(pushed, lft), t);
        if (!tr) continue;
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
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, m;
    cin >> n >> m;
    
    init(n+m+20);
    int s = n+m+10, t = n+m+11;

    frr(u, n) {
        ll x;
        cin >> x;
        add_edge(u, t, x);
    }

    ll sm = 0ll;
    frr(i, m) {
        ll u, v, x;
        cin >> u >> v >> x;
        sm += x;
        add_edge(s, n+i, x);
        add_edge(n+i, u, INF);
        add_edge(n+i, v, INF);
    }

    p(sm - dinic(s, t));
}
