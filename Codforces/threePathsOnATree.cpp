//codeforces.com/contest/1294/problem/F

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

#define maxn 200009
vi adj[maxn];
int prt[maxn];
int dist[maxn];
int seen[maxn];

void dfs(int u, int p) {
    prt[u] = p;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dist[v] = dist[u]+1;
        dfs(v, u);
    }
}

int main() {
    fastio;
    int n;
    cin >> n;
    int u, v;
    fr(i, n-1) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1);
    int v1 = 0;
    frr(i, n) if (dist[i] > dist[v1]) v1 = i;
    ms(dist, 0);
    dfs(v1, v1);
    int v2 = 0;
    frr(i, n) if (dist[i] > dist[v2]) v2 = i;

    if (dist[v2] == n-1) {
        set<int> aux;
        frr(i, n) aux.insert(i);
        aux.erase(v1);
        aux.erase(v2);
        p(n-1);
        cout << v1 << " " << v2 << " " << *aux.begin() << "\n";
        return 0;
    }
    
    int ans = dist[v2];

    queue<pii> q;
    q.push({v1, 0});
    q.push({v2, 0});
    ms(dist, 0);
    int x = v2;
    while (x != v1) {
        x = prt[x];
        q.push({x,0});
    }

    while (!q.empty()) {
        auto aux = q.front();
        q.pop();

        int u = aux.f;
        int d = aux.s;

        if (seen[u]) continue;
        seen[u] = 1;
        dist[u] = d;

        for (auto v: adj[u]) {
            if (seen[v]) continue;
            q.push({v, d+1});
        }
    }

    int v3 = 0;
    frr(i, n) if (dist[i] > dist[v3]) v3 = i;
    p(ans+dist[v3]);
    cout << v1 << " " << v2 << " " << v3 << '\n';
}
