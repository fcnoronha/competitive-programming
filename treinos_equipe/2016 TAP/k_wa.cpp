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
const int N = 1e5 + 1;

vi adj[N];
int n, M, m, Mleaf, mleaf;
int dist[N], c[N], par[N], h[N];

void dfs(int r, int p, int pcur){
    par[r] = p;
    if(r != M){
        dist[r] = dist[p] + c[r];
        h[r] = h[p] + 1;
    }
    if(r == m) pcur = m;
    int cnt = 0;
    for(auto x: adj[r]){
        if(x == p) continue;
        cnt++;
        dfs(x, r, pcur);
    }
    if(cnt == 0){
        if(pcur == M) Mleaf = max(Mleaf, dist[r]);
        else mleaf = max(mleaf, dist[r] - dist[m]);
    }
}


int main(){
    while(scanf("%d%d%d", &n, &M, &m) == 3){
        Mleaf = -1, mleaf = -1;
        frr(i, n) scanf("%d", &c[i]), adj[i].clear(), dist[i] = 0, h[i] = 0;
        fr(i, n-1){
            int a, b; scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(M, M, M);
        int cnt = 0, val = 0, plc = m;
        while(cnt < (h[m] - 1)/2){
            cnt++;
            val += c[par[plc]];
            plc = par[plc];
        }
        int up = min(dist[m] - c[m] - mleaf, dist[m] - 2*val - c[m]);
        int down = min(Mleaf - mleaf, Mleaf - dist[m]);
        printf("%d\n", max(up, down) + c[M] - c[m]);
    }
}
