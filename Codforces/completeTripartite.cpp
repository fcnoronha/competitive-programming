//codeforces.com/contest/1228/problem/D

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

#define maxn 100009

set<int> adj[maxn];
int st[maxn];

int main(){
    fastio;

    int n, m;
    cin >> n >> m;
    fr(i, n) st[i] = 7;

    fr(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vi gid(n, -1);
    vi grp[4];
    frr(g, 3) {
        int fst;
        fr(i, n) {
            if (gid[i] == -1) {
                fst = i;
                break;
            }
        }
        grp[g].pb(fst);
        gid[fst] = g;
        fr(i, n) {
            if (gid[i] != -1 || i == fst) continue;
            if (adj[fst].find(i) == adj[fst].end()) {
                gid[i] = g;
                grp[g].pb(i);
            }
        }
    }

    fr(i, n) {
        if (gid[i] == -1) {
            p(-1);
            return 0;
        }
    }

    int cnt = 0;
    frr(g1, 3) 
        for (int g2 = g1+1; g2 <= 3; g2++) 
            for (int v1: grp[g1]) 
                for (int v2: grp[g2]) {
                    if (adj[v1].find(v2) == adj[v1].end()) {
                        p(-1);
                        return 0;
                    }
                    cnt++;
                }
    if (cnt != m) {
        p(-1);
        return 0;
    }
    pv(gid);
}
