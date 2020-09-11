#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
    
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = LLONG_MAX;

int n, m;

vector<pii> adj[100100];
vector<int> adj2[100100];

int vis[100100];
int pa[100100];
int dis[100100];

void dij1(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 0; i<n; i++){
        dis[i] = INF;
    }
    dis[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        int u = pq.top().snd;
        pq.pop();
        
        for(auto z : adj[u]){
            int v = z.fst;
            int peso = z.snd;
            if(dis[v] > dis[u] + peso){
                dis[v] = dis[u] + peso;
                pq.push({dis[v], v});
            }
        }
    }
    
    
}

void dfs(int x){
    vis[x] = 1;
    for(auto y : adj2[x]){
        if(vis[y]) continue;
        pa[y] = x;
        dfs(y);
    }
}

signed main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
        
    }
    dij1();
    for(int i = 0; i<n; i++){
        int disMin = 0;
        if(adj[i].size() == 0) continue;
        int inicial = adj[i][0].fst;
        int peso = adj[i][0].snd;
        disMin = dis[inicial] + peso;
        for(auto z : adj[i]){
            int y = z.fst;
            int peso = z.snd;
            if(dis[y] + peso < disMin){
                disMin = dis[y] + peso;
            }
        }
        for(auto z : adj[i]){
            int y = z.fst;
            int peso = z.snd;
            if(dis[y] + peso != disMin){
                adj2[i].pb(y);
            }
        }
    }
    dfs(0);
    if(!vis[1]){
        cout << "impossible" << endl;
    }
    else{
        vector<int> caminho;
        int atual = 1;
        while(atual != 0){
            caminho.pb(atual);
            atual = pa[atual];
        }
        caminho.pb(0);
        reverse(all(caminho));
        cout << caminho.size() << " ";
        for(auto x : caminho){
            cout << x << " ";
        }
        cout << endl;
    }
    
}

