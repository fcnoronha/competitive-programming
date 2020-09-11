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
const int INF = 0x3f3f3f3f;

int n;
int last;
vector<int> adj[1000];
int vis[1000];

vector<int> perm;
void dfs(int x){
    last = x;
    vis[x] = 1;
    for(auto y : adj[x]){
        if(vis[y]) continue;
        perm.pb(y);
        dfs(y);
    }
}


signed main(){
    fastio;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            
            char c;
            cin >> c;
            if(i == j) continue;
            if(c=='1'){
                adj[i].pb(j);
            }
        }
    }
    dfs(0);
    int ans = 1;
    for(int i = 1; i<n; i++){
        if(!vis[i]){
            ans = 0;
            break;
        }
    }
    reverse(all(perm));
    if(ans == 0) cout << "impossible" << endl;
    else{
        for(auto x : perm) cout << x << " ";
        cout << 0;
        cout << endl;
    }
    
}

