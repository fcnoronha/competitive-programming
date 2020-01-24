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
const int N = 2e5 + 2;

int indeg[N], seen[N];
vi adj[N];

int bfs(int r){
    queue<int> q;
    q.push(r);
    int ans = 0;
    while(!q.empty()){
        ans++;
        int v = q.front(); q.pop();
        for(auto u: adj[v]){
            indeg[u]--;
            if(!indeg[u] && seen[u]) q.push(u);
        }
    }
    return ans;
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        frr(i, n){
            adj[i].clear();
            indeg[i] = 0;
            seen[i] = 0;
        }
        fr(i, m){
            int a, b; scanf("%d%d", &a, &b);
            adj[a].pb(b);
            indeg[b]++;
        }
        int ans = 0;
        frr(i, n){
            int v; scanf("%d", &v);
            seen[v] = 1;
            if(indeg[v] == 0) ans += bfs(v);
            printf("%d\n", ans);
        }
    }

}
