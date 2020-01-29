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
const int MAXN = 2e6 + 4;


#include <bits/stdc++.h>
using namespace std;

int coresA;
int coresB;
int novosA;
int novosB;
int vis[100100];

int color[100100];
vector<int> adj[100100];
int dfs(int x, int cor){
    color[x] = cor;
    if(cor) novosB++;
    else novosA++;
    for(auto y : adj[x]){
        if(color[y] == cor) return 0;
        if(color[y] == !cor) continue; 
        int t = dfs(y, !cor);
        if(!t) return 0; 
    }
    return 1;
}

void dfs2(int x, int cor){
    vis[x] = 1;
    color[x] = cor;
    if(cor) novosB++;
    else novosA++;
    for(auto y : adj[x]){
        if(vis[y]) continue;
        if(color[y] != -1) dfs2(y, color[y]);
        else dfs2(y, !cor);
    }
}



int main(){
    int n,m;
    cin >> n >> m;
    frr(i,n) {
        color[i] = -1;
    }
    coresA = coresB = 0;
    set<int> A;
    set<int> B;
    
    fr(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        if(c==0){
            A.insert(a);
            A.insert(b);
            if(color[a] == 1 || color[b] == 1){
                cout << "impossible" << endl;
                return 0;
            }
            color[a] = 0;
            color[b] = 0;
        }
        if(c == 2){
            B.insert(a);
            B.insert(b);
            if(color[a] == 0 || color[b] == 0){
                cout << "impossible" << endl;
                return 0;
            }
            color[a] = 1;
            color[b] = 1;
        }
        adj[a].pb(b);
        adj[b].pb(a);
    }


    for(auto x : A){
        novosA = novosB = 0;
        if(vis[x]) continue;
        dfs2(x, 0);
        coresA += novosA;
        coresB += novosB;

    }

    for(auto x : B){
        novosA = novosB = 0;
        if(vis[x]) continue;
        dfs2(x, 1);
        coresA += novosA;
        coresB += novosB;
    }

    
    
    frr(i,n){
        novosA = novosB = 0;
        if(color[i] == -1){
            if(!dfs(i, 0)){
                cout << "impossible" << endl;
                return 0;
            }
            coresA += max(novosA, novosB);
            coresB += min(novosA, novosB);
        }
    }

    cout << coresB << endl;




    






}
