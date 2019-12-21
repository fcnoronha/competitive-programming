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
    ll cap, t, p, flow = 0;
};

vector<FlowEdge> edges;
vector<vi> adj;
vi level, ptr;
queue<int> q;
int cnt;
int e_idx[1000][1000]; 
 
void init(int n) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
    ms(e_idx, 0);
}

void uninit() {
    edges.clear();
    adj.clear();
    level.clear();
    ptr.clear();
    cnt = 0; 
}
 
void add_edge(int u, int v, ll cap, int t, int p) {
    e_idx[u][v] = cnt;
    edges.pb({u, v, cap, t, p});
    edges.pb({v, u, 0ll, t, p});
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

    int t, p, fdp = 0;   
    while (cin >> t >> p && (t || p)) {

        if (fdp) cout << endl;
        fdp = 1;

        init(92000);

        int so = t+p+10, si = so+1, sm1 = 0, sm2 = 0;

        int aux;
        fr(i, t) {
            cin >> aux;
            add_edge(i, si, aux, -1, -1);
            sm1 += aux;
        }

        fr(i, p) {
            cin >> aux;
            add_edge(so, i+t, aux, -1, -1);
            sm2 += aux;
        }

        fr(i, p) 
            fr(j, t) 
                add_edge(i+t, j, 1, j, i);

        if (sm1 != sm2 || dinic(so, si) != sm1) {
            p("Impossible\n");
            uninit();
            continue;
        }

        fr(i, t) 
            fr(j, p) {

                int id1 = e_idx[so][j+t];
                int id2 = e_idx[j+t][i];
                int id3 = e_idx[i][si];

                if (edges[id2].flow == 0) {
                    edges[id2].cap = edges[id2^1].cap = 0;
                    continue;
                }

                int of1, oc1, of2, oc2;
                of1 = edges[id2].flow;
                of2 = edges[id2^1].flow;
                oc1 = edges[id2].cap;
                oc2 = edges[id2^1].cap;

                edges[id1].flow--;
			    edges[id1^1].flow++;
			
                edges[id2].flow = edges[id2].cap = 0;
                edges[id2^1].flow = edges[id2^1].cap = 0;
			    
                edges[id3].flow--;
			    edges[id3^1].flow++;

                if (dinic(so, si)) continue;

                edges[id2].flow = of1;
                edges[id2^1].flow = of2;
                edges[id2].cap = oc1;
                edges[id2^1].cap = oc2;

                edges[id1].flow++;
			    edges[id1^1].flow--;

                edges[id3].flow++;
			    edges[id3^1].flow--;
            }


        int ans[t][p];
        ms(ans, 0);
        for (auto e: edges) {

            if (e.u == so || e.u == si) continue;
            if (e.v == so || e.v == si) continue;
            if (e.flow <= 0) continue;
            if (e.t == -1 || e.p == -1) continue;
            ans[e.t][e.p] = 1;
        }

        fr(i, t) {
            fr(j, p) {
                if (ans[i][j]) cout << "Y";
                else cout << "N";
            }
            cout << endl;
        }

        uninit();
    }
}
