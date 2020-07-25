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

struct FlowEdge {
    int u, v;
    pair<pii, int> tp;
    ll cap, flow = 0;
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
 
void add_edge(int u, int v, ll cap, pair<pii, int> tp={{INF,INF},-1}) {
    edges.pb({u, v, tp, cap});
    edges.pb({v, u, tp, 0ll});
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
 
int get_sum(int x) {
    int ret = 0;
    while (x) {
        ret += x%10;
        x /= 10;
    }
    return ret;
}

int main() {
    fastio;

    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    int bus[n], trol[m];
    string sb[n], st[m];
    fr(i,n) {
        cin >> sb[i];
        bus[i] = stoi(sb[i]);
    }
    fr(i,m) {
        cin >> st[i];
        trol[i] = stoi(st[i]);
    }

    init(5000);
    int src = 0, snk = 2, clk = 5;

    map<int, int> mb, mt;
    map<int, vi> posl, posr;
    fr(i,n) {
        int l = get_sum(bus[i]/1000); 
        int r = get_sum(bus[i]%1000);
        posl[l].pb(i);
        posr[r].pb(i);
        add_edge(src, clk, 1);
        add_edge(clk, clk+1, 1); // rgt
        add_edge(clk, clk+2, 1); // lft
        mb[i] = clk;
        clk+=3;
    } 

    fr(i,m) {
        int l = get_sum(trol[i]/1000); 
        int r = get_sum(trol[i]%1000);
        add_edge(clk, snk, 1);
        add_edge(clk+1, clk, 1); // rgt
        add_edge(clk+2, clk, 1); // lft
        for (auto j: posr[l]) add_edge(mb[j]+1, clk+2, 1, {{i,j}, 2});
        for (auto j: posl[r]) add_edge(mb[j]+2, clk+1, 1, {{i,j}, 1});
        mt[i] = clk;
        clk+=3;
    }

    int mf = dinic(src, snk);
    p(mf);
    for (auto e: edges) {
        if (e.cap == 0 || e.flow != 1) continue;
        int i = e.tp.f.f, j = e.tp.f.s, aux = e.tp.s;
        if (aux == -1) continue;
        if (aux == 1) {
            cout << "AT " << sb[abs(j)] << " " << st[abs(i)] << '\n';
        }
        else {
            cout << "TA " << st[i] << " " << sb[j] << '\n'; 
        }
    }
}
