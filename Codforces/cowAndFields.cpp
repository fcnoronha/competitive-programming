//codeforces.com/contest/1307/problem/D

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
int special[maxn], dist[2][maxn];

int main(){
    fastio;

    ms(dist, INF);

    int n, m, k, aux;
    cin >> n >> m >> k;
    fr(i, k) {
        cin >> aux;
        special[aux] = 1;
    } 
    fr(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // BFS from 1
    queue<int> q;
    int *ds = dist[0];
    q.push(1); ds[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: adj[u]) {
            if (ds[v] < INF) continue;
            ds[v] = ds[u]+1;
            q.push(v);
        }
    }

    // BFS from n
    ds = dist[1];
    q.push(n); ds[n] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: adj[u]) {
            if (ds[v] < INF) continue;
            ds[v] = ds[u]+1;
            q.push(v);
        }
    }

    vector<pii> a;
    frr(i, n) {
        if (!special[i]) continue;
        a.pb({dist[0][i]-dist[1][i], i});
    }
    sort(all(a));
    int mx, bst;
    mx = bst = -INF;
    for (auto x: a) {
        int u = x.s;
        bst = max(bst, mx+dist[1][u]);
        mx = max(mx, dist[0][u]);
    }

    p(min(bst+1, dist[0][n]));
}
