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
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

ll pd[3000][3000];
vector<int> adj[3000];

int k;

signed main(){
    fastio;
    int n;
    cin >> n >> k;
    for(int i = 1; i<=n-1; i++){
        int x;
        cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    pd[1][1] = 1;
    for(int i = 2; i<=n; i++) {
        pd[i][i] = (pd[i-1][i-1] *1ll* i)%MOD;
        pd[2][i] = 2;
    }
    for(int j = 3; j<=k; j++){
        for(int i = j+1; i<=n; i++){
            pd[j][i] = ((j*1ll*pd[j-1][i-1])%MOD + ( (j-1) *1ll* pd[j][i-1] )%MOD)%MOD;
        }
    }
    cout << pd[k][n] << endl;
}
