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

#define maxn 2123

vi adj[maxn];
int ans[maxn], vis[maxn];

int main() {
    fastio;
    int n, x, y;
    cin >> n >> x >> y;

    frr(i, n-1) {
        adj[i].pb(i+1);
        adj[i+1].pb(i);
    }

    adj[x].pb(y);
    adj[y].pb(x);

    frr(i, n) {
        ms(vis, 0);

        queue<pii> q;
        q.push({0, i});
        while (!q.empty()) {
            int u = q.front().s;
            int d = q.front().f;
            q.pop();

            if (vis[u]) continue;
            vis[u] = 1;

            if (u > i) ans[d]++;
            for (auto v: adj[u]) q.push({d+1, v});
        }
    }

    frr(i, n-1) p(ans[i]);
}
