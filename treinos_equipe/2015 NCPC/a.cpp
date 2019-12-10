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

int dist[100100];
int vis[100100];
multiset<int> arvores;


vector<int> adj[100100];
vector<int> visitados;
void dfs(int x){
    visitados.pb(x);
    vis[x] = 1;
    for(auto y : adj[x]) {
        if(!vis[y]){
            dist[y] = dist[x] + 1;
            dfs(y);
        }
    }
}

int main(){
    fastio;

    int n, m;
    cin >> n >> m;

    fr(i,m){
        int a ,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

        fr(i,n){
            if(!vis[i]){
                dist[i] = 0;
                dfs(i);
                int distMax = -1;
                int vMax = 0;
                for(auto j : visitados){
                    if(dist[j] > distMax){
                        distMax = dist[j];
                        vMax = j;
                    }
                }
                for(auto j : visitados){
                    dist[j] = 0;
                    vis[j] = 0;
                }
                dist[vMax] = 0;
                visitados.clear();
                dfs(vMax);
                
                int diametro = 0;
                for(auto j : visitados) {
                    diametro = max(diametro, dist[j]);
                }
                arvores.insert(diametro);
                visitados.clear();
            }
        }


    while(arvores.size() > 1){
        auto x = arvores.begin();
        auto y = arvores.end();
        y--;
        arvores.erase(x);
        arvores.erase(y);


        int distNova = max(*x, *y);
        distNova = max(distNova, ((*x)+1)/2 + ((*y)+1)/2 + 1);
        arvores.insert(distNova);
    }

    cout << *arvores.begin() << endl;
   



}
