#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i, n) for (int i = 0; i < n; i++)
#define frr(i, n) for (int i = 1; i <= n; i++)
#define ms(x, i) memset(x, i, sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define olar cout << "olar" << endl
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<vector<int>, vector<int>> parzao;

vector<pair<int,int>> adj[200200];
vector<pair<int,int>> radj[200200];
int arestasVis[200200];
int vis[100100];
int rvis[100100];

void dfs(int x){
    vis[x] = 1;
    for(auto z : adj[x]){
        int aresta = z.fst;
        int y = z.snd;
        if(!vis[y]) {
            arestasVis[aresta] = 1;
            dfs(y);
            
        }
    }
}

void rdfs(int x){
    rvis[x] = 1;
    for(auto z : radj[x]){
        int aresta = z.fst;
        int y = z.snd;
        if(!rvis[y]) {
            arestasVis[aresta] = 1;
            rdfs(y);
        }
    }
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pii> arest;
        for(int i = 1; i<=n; i++){
            vis[i] = 0;
            rvis[i] = 0;
            adj[i].clear();
            radj[i].clear();
        }
        for(int i = 0; i<m; i++){
            arestasVis[i] = 0;
            int a, b;
            cin >> a >> b;
            adj[a].pb({i,b});
            radj[b].pb({i,a});
            arest.pb({a,b});
        }
        dfs(1);
        rdfs(1);
        vector<int> ans;
        for(int i = 0; i<m; i++){
            if(ans.size() == m-2*n) break;
            if(!arestasVis[i]){
                ans.pb(i);     
            }
        }
        for(auto y : ans){
            cout << arest[y].fst << " " << arest[y].snd << endl;
        }
    }
    
}