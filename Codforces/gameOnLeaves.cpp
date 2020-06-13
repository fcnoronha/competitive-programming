//codeforces.com/contest/1363/problem/C

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

#define maxn 1123

vi adj[maxn];
int deg[maxn], is_especial[maxn], vis[maxn];

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        fr(i, n+10) {
            vis[i] = is_especial[i] = deg[i] = 0;
            adj[i].clear();
        }

        fr(i, n-1) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
            deg[u]++, deg[v]++;
        }

        if (deg[x] <= 1) {
            p("Ayush");
            continue;
        }

        bool player = 0;
        for (auto u: adj[x]) is_especial[u] = 1;

        while (1) {
            int u = -1;

            frr(i, n) {
                if (vis[i] == 0 && deg[i] == 1 && is_especial[i] == 0 && i != x) {
                    u = i;
                    break;
                }
            }
            if (u != -1) {
                player = !player;
                vis[u] = 1;
                for (auto v: adj[u]) deg[v]--;
                continue;
            }
            
            if (deg[x] == 1) {
                if (player == 0) p("Ayush");
                if (player == 1) p("Ashish");
                break;
            }
            frr(i, n) {
                if (vis[i] == 0 && deg[i] == 1 && is_especial[i] == 1) {
                    u = i;
                    break;
                }
            }
            
            player = !player;
            vis[u] = 1;
            for (auto v: adj[u]) deg[v]--;
        }
    }    
}
