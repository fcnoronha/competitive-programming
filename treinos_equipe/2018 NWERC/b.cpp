#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)    memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
    
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<int,pair<int,int>> piii;
const int INF = LLONG_MAX;

vector<int> adj[400400], radj[400400];
int tempo[400400];
int falta[400400], ff[400400];
int inicial[400400];
int vis[400400];

signed main(){
    fastio;
    int n;
    cin >> n;
    priority_queue<pair<int,int>> fila;
    int passado = 0;
    for(int i = 1; i<=n; i++){
        cin >> tempo[i];
        inicial[i] = tempo[i];
        cin >> falta[i];
        for(int j = 0; j<falta[i]; j++){
            int req;
            cin >> req;
            adj[req].pb(i);
            radj[i].pb(req);
        }
    }

    queue<int> q; 
    for(int i = 1; i<=n; i++){
        ff[i] = adj[i].size();
        if (adj[i].size() == 0) {
            q.push(i);
        }
    }
    while(q.size()){
        int topo = q.front();
        q.pop();
        for(auto y : radj[topo]){
            tempo[y] = max(tempo[y], tempo[topo]);
            ff[y]--;
            if(ff[y] == 0) q.push(y);
        }
    }

    for(int i = 1; i<=n; i++){
        if(falta[i] == 0) fila.push({tempo[i], i});
    }
    int ans = -1;
    while(fila.size()){
        int topo = fila.top().snd;
        ans =max(ans,inicial[topo] + passado);
        fila.pop();
        for(auto y : adj[topo]){
            falta[y]--;
            if(falta[y] == 0) fila.push({tempo[y],y});
        }
        passado++;
    }
    cout << ans << endl;

}