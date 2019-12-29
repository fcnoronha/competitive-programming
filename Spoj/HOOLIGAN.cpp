//br.spoj.com/problems/HOOLIGAN/

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
    int cap, flow = 0;
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
 
void add_edge(int u, int v, int cap) {
    edges.pb({u, v, cap});
    edges.pb({v, u, 0});
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
 
int dfs(int u, int pushed, int t) {
    if (pushed == 0)
        return 0;
    if (u == t)
        return pushed;
    for (int& cid = ptr[u]; cid < adj[u].size(); cid++) {
        int id = adj[u][cid];
        int v = edges[id].v;
        if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
            continue;
        int tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow), t);
        if (tr == 0)
            continue;
        edges[id].flow += tr;
        edges[id^1].flow -= tr;
        return tr;
    }
    return 0;
}
 
int dinic(int s, int t) {
    int f = 0;
    while (true) {
        fill(all(level), -1);
        level[s] = 0;
        q.push(s);
        if (!bfs(t)) break;
        fill(all(ptr), 0);
        while (int pushed = dfs(s, INF, t)) 
            f += pushed;
    }
    return f;
}
 
int main(){
    fastio;
 
    int n, m, g;
    while (cin >> n >> m >> g && n) {
 
        init((n*10)*(10*n));
 
        int in[n+10], out[n+10];
        int games_dn[n+10][n+10], pts[n+10], game[n+10][n+10];
        int id = 2;
        
        ms(games_dn, 0);
        ms(pts, 0);
        
        // Vin and Vout for each v
        fr(i, n) {
            in[i] = id++;
            out[i] = id++;
            for (int j = i+1; j < n; j++)
                game[i][j] = game[j][i] = id++;
        }
        int src = id++, sik = id++;
 
        // reading games
        int a, b;
        char op;
        fr(i, g) {
 
            cin >> a >> op >> b;
 
            // draw
            if (op == '=') 
                pts[a]++, pts[b]++; 
            else if (op == '<') 
                pts[b] += 2;
            else 
                pts[a] += 2;
            
            // those teams have 1 less game to do
            games_dn[a][b]++;
            games_dn[b][a]++;
        }
 
        // Making team 0 win all possible games
        frr(i, n-1) 
            pts[0] += (m - games_dn[0][i])*2;

        // a team have max_pts[i] at the beggining
        fr(i, n) 
            add_edge(src, in[i], INF);  
        
        // a team give CAN available points to match
        // a game give up to 2*CAN to a team or distributes it
        int t_gm_left = 0; // total games left
        frr(i, n-1) {
            for (int j = i+1; j < n; j++) {
                
                int can = (m - games_dn[i][j]);
                if (can == 0) continue;
                
                t_gm_left += can;
 
                add_edge(in[i], game[i][j], can);
                add_edge(in[j], game[i][j], can);
 
                add_edge(game[i][j], out[i], 2*can);
                add_edge(game[i][j], out[j], 2*can);
            }
        }
 
        // a team can make up to pts[0]-pts[i] points to not be the winner
        int badbadbad = 0;
        frr(i, n-1) {
 
            int max_pts = pts[0]-1-pts[i];
            if (max_pts < 0) badbadbad = 1;
        
            add_edge(out[i], sik, max_pts);
        }
 
        if (badbadbad) {
            p("N");
            uninit();
            continue;
        }
        
        int mf = dinic(src, sik);
        if (mf == t_gm_left*2) p("Y");
        else p("N");
 
        uninit();
    }
}