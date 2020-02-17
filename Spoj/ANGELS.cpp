//www.spoj.com/problems/ANGELS/

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

#define maxn 300
#define maxv 500000
int grid[maxn][maxn], idh[maxn][maxn], idv[maxn][maxn];

vi adj[maxv];
int l[maxv], r[maxv], seen[maxv];

bool dfs(int u) {
    if (seen[u]) return 0;
    seen[u] = 1;
    for (int v: adj[u]) {
        if (r[v] != -1) continue;
        l[u] = v;
        r[v] = u;
        return 1;
    }
    for (int v: adj[u]) {
        if (dfs(r[v])) {
            l[u] = v;
            r[v] = u;
            return 1;
        }
    }
    return 0;
}

int kuhn(int n) {
    fr(i, n) l[i] = r[i] = -1;
    int ok = 1, cnt = 0;
    while (ok--) {
        fr(i, n) seen[i] = 0;
        fr(i, n) {
            if (l[i] == -1 && dfs(i)) {
                ok = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int h, w;
        cin >> h >> w;

        fr(i, h) {
            fr(j, w) {
                char x;
                cin >> x;
                if (x == 'H') grid[i][j] = 0;
                else if (x == 'D') grid[i][j] = 1;
                else grid[i][j] = 2;
            }
        } 
        int clk = 0, tem;
        fr(i, h) {
            clk++;
            tem = 0;
            fr(j, w) {
                if (grid[i][j]) {
                    if (grid[i][j] == 2) tem = 1;
                    continue;
                }
                if (tem) {
                    clk++;
                    tem = 0;
                }
                idh[i][j] = clk;
            }
        } 
        fr(j, w) {
            clk++;
            tem = 0;
            fr(i, h) {
                if (grid[i][j]) {
                    if (grid[i][j] == 2) tem = 1;
                    continue;
                }
                if (tem) {
                    clk++;
                    tem = 0;
                }
                idv[i][j] = clk;
            }
        }

        fr(i, h) {
            fr(j, w) {
                if (grid[i][j]) continue;
                adj[idh[i][j]].pb(idv[i][j]);
            }
        }

        p(kuhn(clk+10));
        fr(i, clk+10) adj[i].clear();
    }
}
