//www.spoj.com/problems/DISJPATH/

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
    int u, v;
    ll cap, rot, flow = 0;
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
 
void add_edge(int u, int v, ll cap, int rot) {
    edges.pb({u, v, cap, rot});
    edges.pb({v, u, 0ll, rot});
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

void print_path(int v, int to) {
    for (auto id: adj[v]) {
        FlowEdge &e = edges[id];
        if (e.flow <= 0) continue;
        if (e.rot != -1) cout << e.rot << " ";
        e.flow = 0;
        print_path(e.v, to);
        return;
    }
    return;
}

int main(){
    fastio;

    int in[5009], out[5009];

    int cs = 1;
    int k, n;
    while (cin >> k >> n && k && n) {

        init(n << 2);

        int aux = 0;
        frr(i, n) {
            in[i] = aux++;
            out[i] = aux++;
            add_edge(in[i], out[i], 1, i);
        }

        string str;
        getline(cin, str);
        frr(from, n) { 
            getline(cin, str);
            istringstream ss(str);
            int to;
            while(ss >> to) 
                add_edge(out[from], in[to], 1, -1);
        }

        cout << "Case " << cs++ << ":\n";
        if (dinic(out[1], in[2]) < k)
            cout << "Impossible\n";
        else 
            while (k--) {
                cout << "1 ";
                print_path(out[1], in[2]);
                cout << "2\n";
            }
        
        uninit();
        cout << endl;
    }
}
