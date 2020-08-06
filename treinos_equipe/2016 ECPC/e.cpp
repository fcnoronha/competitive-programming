#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)    memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
    
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;

vector<int> adj[100100];
int dist[100100];
int vis[100100];

int n;


void bfs(){
    queue<int> fila;
    fila.push(n);
    for(int i = 1; i<=n; i++){
        dist[i] = INF;
        vis[i] = 0;
    }
    dist[n] = 0;
    vis[n] = 1;
    
    while (!fila.empty()) {
        int v = fila.front();
        fila.pop();
        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = 1;
                fila.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }
}



signed main(){
    freopen("jumping.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--){

        scanf("%d", &n);
        for(int i = 1; i<=n; i++) adj[i].clear();
        for(int i = 1; i<=n; i++){
            int x;
            scanf("%d", &x);
            if(i - x >= 1) adj[i-x].pb(i);
            if(i + x <= n) adj[i+x].pb(i);
        }
        bfs();
        for(int i = 1; i<=n; i++) {
            if(dist[i] >= INF) printf("-1\n");
            else
            printf("%d\n", dist[i]);
        }
        
    }
    
}