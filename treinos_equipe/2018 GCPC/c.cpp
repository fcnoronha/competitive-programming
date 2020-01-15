#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(iii, x.size()) cout << x[iii] << " \n"[iii==x.size()-1]
#define pvv(x, n) for(int iii = 1, vaca = nnn; i <= nnn;i++) cout << x[i] << " \n"[iii==nnn];

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
const int N = 1e3 + 1;


int w[N][N], vis[N];
int dist[N];

vi adj[N];

stack<int> top;

void dfs(int r){
    vis[r] = 1;
    for(auto v: adj[r]){
        if(vis[v]) continue;
        dfs(v);
    }
    top.push(r);
}

int main(){
    int n, m; scanf("%d%d", &n, &m);
    fr(i, m){
        int a, b, ww;
        scanf("%d%d%d", &a, &b, &ww);
        adj[a].pb(b);
        w[a][b] = max(w[a][b], ww);
    }
    int ans = 0;
    frr(i, n) if(!vis[i]) dfs(i);
    while(!top.empty()){
        for(auto v: adj[top.top()]){
            dist[v] = max(dist[top.top()] + w[top.top()][v], dist[v]);
            ans = max(dist[v], ans);
        }
        top.pop();
    }
    printf("%d\n", ans);
}
