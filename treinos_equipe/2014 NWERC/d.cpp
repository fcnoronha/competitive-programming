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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
const int INF = 0x3f3f3f3f;

ll n, m;

ll bolas[500500];
vector<ll> adj[500500];
ll ans[500500];
ll grau[500500];
map<int,int> onQueue;
int main(){
    fastio;
    
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i<=m; i++){
        char c;
        cin >> c;
        if(c == 'L') ans[i] = 0;
        else ans[i] = 1;
        ll a, b;
        cin >> a >> b;
        adj[i].pb(a);
        adj[i].pb(b);
        grau[a]++;
        grau[b]++;
    }
    queue<ll> fila;
    for(int i = 1; i<=m; i++){
        if(grau[i] == 0) {
            fila.push(i);
            onQueue[i] = 1;
        }
    }
    bolas[1] = n;
    while(!fila.empty()){
        ll topo;
        topo = fila.front();
        fila.pop();
        ll esq = adj[topo][0];
        ll dir = adj[topo][1];
        bolas[esq] += bolas[topo]/2ll;
        bolas[dir] += bolas[topo]/2ll;
        if(bolas[topo]%2) {
            if(ans[topo]){
                bolas[dir]++;
            }
            else{
                bolas[esq]++;
            }
            ans[topo] = !ans[topo];
        }

        grau[esq]--;
        if(esq != 0 && grau[esq] == 0 && onQueue[esq] == 0) {
            onQueue[esq] = 1;
            fila.push(esq);
        }
        grau[dir]--;
        if(dir != 0 && grau[dir] == 0 && onQueue[dir] == 0){
            onQueue[dir] = 1;
            fila.push(dir);
        } 
    }
    for(ll i = 1; i<=m; i++){
        if(ans[i]) cout << "R";
        else cout << "L";
    }
    cout << endl;


}