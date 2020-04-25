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

#define maxn 212345

vector<pii> adj[maxn];
pii edg[maxn];
int flag[maxn], vis[maxn], edt[maxn];

int cnta, cntb, ndeu;
void dfs(int u, bool c) {

    if (flag[u] != -1 && c != flag[u]) ndeu = 1;

    if (vis[u]) return;
    vis[u] = 1;
    flag[u] = c;

    if (c) cnta++;
    else cntb++;

    for (auto x: adj[u]) {
        if (x.s != 1) continue;
        dfs(x.f, !c);
    }
}

int main() {
    fastio;

    ms(flag, -1);

    int n, m;
    cin >> n >> m;
    fr(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v,c});
        adj[v].pb({u,c});
        edg[i] = {u,v};
        edt[i] = c;
    }

    queue<int> q;

    fr(i, m) {
        if (edt[i] != 2) continue;
        int u = edg[i].f, v = edg[i].s;
        flag[u] = flag[v] = 1;
        q.push(u);
        q.push(v);
    }

    fr(i, m) {
        if (edt[i] != 0) continue;
        int u = edg[i].f, v = edg[i].s;
        if (flag[u] == 1 || flag[v] == 1) {
            p("impossible");
            return 0;
        } 
        flag[u] = flag[v] = 0;
        q.push(u);
        q.push(v);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        for (auto x: adj[u]) {
            int v = x.f;
            int c = x.s;
            
            if (c == 0) {
                if (flag[v] == 1) {
                    p("impossible");
                    return 0;
                }
                flag[v] = 0;
                q.push(v);
            } 
            else if (c == 1) {
                if (flag[u] == 1) {
                    if (flag[v] == 1) {
                        p("impossible"); return 0;
                    }
                    flag[v] = 0;
                    q.push(v);
                }
                else {
                    if (flag[v] == 0) {
                        p("impossible"); return 0;
                    }
                    flag[v] = 1;
                    q.push(v);
                }
            }
            else if (c == 2) {
                if (flag[v] == 0) {
                    p("impossible"); return 0;
                }
                flag[v] = 1;
                q.push(v);
            }
        }
    }

    int ans = 0;
    frr(i, n) ans += (flag[i] == 1);

    frr(i, n) {
        if (vis[i]) continue;
        cnta = cntb = 0;
        dfs(i, 0);
        ans += min(cnta, cntb);

        if (ndeu) {
            p("impossible");
            return 0;
        }
    }

    p(ans);
}
