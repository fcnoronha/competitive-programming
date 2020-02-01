//open.kattis.com/problems/pieceittogether


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

    int h, w;
    cin >> h >> w;

    init(h*w*10);

    string s[h];
    fr(i, h) cin >> s[i];

    int cntb = 0, cntw = 0, clk = 0;
    map<int, int> id, auxv, auxh;
    fr(i, h) {
        fr(j, w) {
            if (s[i][j] == 'B') {
                cntb++;
                id[w*i+j] = clk++;
                auxv[w*i+j] = clk++;
                auxh[w*i+j] = clk++;
            }
            else if (s[i][j] == 'W') {
                cntw++;
                id[w*i+j] = clk++;
            }
        }
    }

    int so = clk++, si = clk++;

    if (cntw != 2*cntb) {
        p("NO");
        return 0;
    }

    fr(i, h) {
        fr(j, w) {
            if (s[i][j] != 'B') continue;

            add_edge(so, id[i*w+j], 2);
            add_edge(id[i*w+j], auxv[w*i+j], 1);
            add_edge(id[i*w+j], auxh[w*i+j], 1);

            // vertical
            if (i && s[i-1][j] == 'W') {
                add_edge(auxv[w*i+j], id[w*(i-1)+j], 1);
            }
            if (i < h-1 && s[i+1][j] == 'W') {
                add_edge(auxv[w*i+j], id[w*(i+1)+j], 1);
            }

            // horizontal    
            if (j && s[i][j-1] == 'W') {
                add_edge(auxh[w*i+j], id[w*i+j-1], 1);
            }
            if (j < w-1 && s[i][j+1] == 'W') {
                add_edge(auxh[w*i+j], id[w*i+j+1], 1);
            }         
        }
    }

    fr(i, h) {
        fr(j, w) {
            if (s[i][j] != 'W') continue;

            add_edge(id[i*w+j], si, 1);     
        }
    }
    
    if (dinic(so,si) == cntw) p("YES");
    else p("NO");
}
