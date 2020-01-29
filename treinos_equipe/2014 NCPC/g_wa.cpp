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
const int N = 1e3 + 1;

int par[N], vis[N], pro[N];

int id[N], idd = 0, incycle[N], sz[N];

int memo[N][N];
int n, k;
int cycle[N];
vi adj[N];

int dp(int i, int s){
    if(s > k) return -INF;
    if(i == idd) return s;
    if(s == k) return k;
    if(memo[i][s] != -1) return memo[i][s];
    for(int j = 0; j <= cycle[i]; j++){
        memo[i][s] = max(memo[i][s], dp(i+1, s + j + sz[i]));    
    }
    return memo[i][s];
}




int dfs(int r, int p){
    par[r] = p;
    pro[r] = 1;
    for(auto v: adj[r]){
        if(pro[v]){
            int plc = r;
            while(plc != v){
                id[plc] = idd;
                incycle[plc] = 1;
                sz[idd]++;
                plc = par[plc];
            }
            sz[idd]++;
            incycle[plc] = 1;
            id[plc] = idd++;
        }
        else if(id[v] != -1){
            id[r] = id[v];
        }
        else id[r] = dfs(v, r);
    }
    pro[r] = 0;
    return id[r];
}

int main(){
    scanf("%d%d", &n, &k);
    ms(id, -1);
    ms(memo, -1);
    frr(i, n){
        int a; scanf("%d", &a);
        adj[i].pb(a);
    }
    frr(i, n){
        if(id[i] == -1) dfs(i, i);
        if(!incycle[i]) cycle[id[i]]++;
    }
    int plc = dp(0, 0);
    if(plc > 0){
        printf("%d\n", plc);
    }
    else printf("0\n");
}
