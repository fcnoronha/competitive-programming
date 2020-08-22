//acm.timus.ru/problem.aspx?space=1&num=1533

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
#define pv(x) for (auto y: x) cout << y << " "; cout << endl;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 123

vi pt[maxn];
bool g[maxn][maxn];

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

set<int> stu, stz, stl, str;
 
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

int s, t;
int vis[maxn+maxn];

void reach(int u, set<int> &st) {
    if (vis[u]) return;
    vis[u] = 1;
    st.insert(u);
    for (int id: adj[u]) {
        int v = edges[id].v;
        if (v == s || v == t) continue;
        int lft = edges[id].cap - edges[id].flow;
        if (lft == 0) continue;
        reach(v, st);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n;
    cin >> n;

    fr(u, n) fr(v, n) {
        int x;
        cin >> x;
        if (x) g[u][v] = 1;
    }

    fr(k, n) fr(i, n) fr(j, n) 
        g[i][j] |= (g[i][k]&g[k][j]);

    s = n+n+2, t = s+1;
    init(t+10);
    fr(u, n) {
        add_edge(s, u, 1);
        add_edge(u+n, t, 1);
        fr(v, n) 
            if (g[u][v])
                add_edge(u, n+v, 1); 
    }

    int d = dinic(s, t);

    fr(u, n) {
        stl.insert(u);
        str.insert(u+n);
        stu.insert(u);
    }

    for (auto e: edges) {
        if (e.u == s || e.v == t || e.flow == 0 || e.cap == 0) continue;
        stu.erase(e.u);
    }

    for (auto u: stu) {
        ms(vis, 0);
        reach(u, stz);
    }

    set<int> ans;
    for (auto x: stl) 
        if (stz.find(x) == stz.end()) ans.insert(x);
    for (auto x: str) 
        if (stz.count(x)) ans.insert(x);

    set<int> anss;
    fr(u, n) 
        if (ans.find(u) == ans.end() && ans.find(u+n) == ans.end())
            anss.insert(u+1);

    assert(anss.size() == n-d);
    p(n-d);
    pv(anss);
}

