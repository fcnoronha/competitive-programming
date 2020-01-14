//codeforces.com/contest/1272/problem/E

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
int a[maxn], ans[maxn];

void bfs(vi from, vi to) {

    int dist[maxn];
    ms(dist, INF);

    queue<int> q;

    for (auto f: from) {
        dist[f] = 0;
        q.push(f);
    }

    while (q.size()) {

        int v = q.front();
        q.pop();

        for (auto u: adj[v]) {
            if (dist[u] < INF) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }

    for (auto t: to) 
        if (ans[t] == INF) ans[t] = dist[t];
}

int main() {

    int n;
    cin >> n;

    fr(i, n) cin >> a[i];

    vi even, odd;
    fr(i, n) {

        if (a[i]%2) odd.pb(i);
        else even.pb(i);

        int pos = i + a[i];
        if (pos < n) adj[pos].pb(i);
        pos = i - a[i];
        if (pos >= 0) adj[pos].pb(i);
    }

    ms(ans, INF);
    bfs(even, odd);
    bfs(odd, even);

    fr(i, n) {
        if (ans[i] == INF) ans[i] = -1;
        cout << ans[i] << " ";
    }

    cout << endl;
}