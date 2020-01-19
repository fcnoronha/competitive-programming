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
 
vi adj[1000];
int vis[1000];
int ans = INF;
 
int dfs(int v, int dest) {
    
    queue<pii> q;
    q.push({v, 1});

    while (!q.empty()) {
        
        auto x = q.front();
        q.pop();

        int v = x.f;
        int d = x.s;

        if (v == dest) return d;

        if (vis[v]) continue;
        vis[v] = 1;

        for (auto u: adj[v]) 
            q.push({u, d+1});
    }

    return INF;
}
 
int main(){
 
    fastio;
 
    int n;
    cin >> n;
 
    ll cnt[70];
    ms(cnt, 0);
 
    ll aux;
    vl v;
    fr(i, n) {
 
        cin >> aux;
        if (aux) v.pb(aux);

        fr(bit, 64) 
            if (aux & (1LL << bit)) 
                cnt[bit]++;
    }

    fr(i, 63) {
        if (cnt[i] >= 3) {
            p("3");
            return 0;
        }
    }

    n = v.size();
    fr(i, n) 
        fr(j, n) 
            if (i != j && v[i]&v[j]) 
                adj[i].pb(j);
            
    fr(i, n) {
        fr(j, adj[i].size()) {
            fill(vis, vis+n, 0);
            int sai = adj[i][j];
            adj[i].erase(adj[i].begin() + j);

            int d = dfs(i, sai);
            if (d > 2) ans = min(ans, d);

            adj[i].pb(sai);
        }
    }
    
 
    if (ans == INF) ans = -1;
    p(ans);
}
