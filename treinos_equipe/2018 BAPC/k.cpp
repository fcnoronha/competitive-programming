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
const int N = 1e5 + 2;

int deg[N], pre[N], clk = 0;
vi leafs;

vi adj[N];

void dfs(int r, int p){
    pre[r] = clk++;
    for(auto v: adj[r]){
        if(v == p) continue;
        dfs(v, r);
    }
}

bool mycomp(int a, int b){
    return pre[a] < pre[b];
}

int main(){
    int n, h; scanf("%d%d", &n, &h);
    fr(i, n-1){
        int a, b; scanf("%d%d", &a, &b);
        deg[a]++;
        deg[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    fr(i, n){
        if(deg[i] == 1) leafs.pb(i);
    }
    dfs(h, h);
    sort(all(leafs), mycomp);
    int sz = leafs.size();
    printf("%d\n", (sz+1)/2);
    fr(i, sz/2){
        printf("%d %d\n", leafs[i], leafs[i+(sz+1)/2]);
    }
    if(sz%2){
        printf("%d %d\n", h, leafs[sz/2]);
    }
}
