#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define int long long int
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;


vector<int> adj[200200];

map<pii,int> bloqueio;
int marcas[200200];
signed main(){
    fastio;
    int r, s, m, d, n;
    cin >> r >> s >> m >> d >> n;
    for(int i = 1; i<=r; i++){
        cin >> marcas[i];
    }
    for(int i = 1; i<=s+m+d; i++){
        int k;
        cin >> k;
        for(int j = 0; j<k; j++){
            int z;
            cin >> z;
            adj[i].pb(z);
        }
    }
    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;
        bloqueio[{a,b}] = 1;
        bloqueio[{b,a}] = 1;
    }
    __int128 ans = 0;
    for(int i = 1; i<=s; i++){
        for(int j = s+1; j<=s+m; j++){
            for(int k = s+m+1; k<=s+m+d; k++){
                if(bloqueio[{i,j}] || bloqueio[{i,k}] || bloqueio[{j,k}]) continue;
                set<int> ingredientes;
                for(auto x : adj[i]) ingredientes.insert(x);
                for(auto x : adj[j]) ingredientes.insert(x);
                for(auto x : adj[k]) ingredientes.insert(x);
                __int128 cnt= 1;
                for(auto x : ingredientes){
                    if(cnt * (marcas[x] / 10L) >1e18L || cnt * (marcas[x] / 4) >1e18L || cnt * (marcas[x]/2) > 1e18L){
                        cout << "too many" << endl;
                        exit(0);
                    }
                    int c = cnt * marcas[x];
                    if(c / marcas[x] != cnt || c / cnt != marcas[x]){
                        cout << "too many" << endl;
                        exit(0);
                    }
                    cnt = c;
                    
                    if(cnt > 1e18L || ans + cnt > 1e18L){
                        cout << "too many" << endl;
                        exit(0);
                    }
                    
                }
                ans += cnt;
            }
        }
    }
    int novaAns = (int) ans;
    cout << novaAns << endl;
    
}