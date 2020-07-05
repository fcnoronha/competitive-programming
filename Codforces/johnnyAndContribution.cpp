//codeforces.com/contest/1362/problem/D

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

#define maxn 512345

vi adj[maxn], in_col[maxn];
int seen[maxn];

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    fr(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    frr(i, n) {
        int c;
        cin >> c;
        in_col[c].pb(i);
    }

    vi ans;
    frr(c, n) {
        for (auto u: in_col[c]) {

            seen[u] = c;
            set<int> st;
            int deu = 1;
            for (auto v: adj[u]) {
                if (seen[v]) st.insert(seen[v]);
                if (seen[v] == c) deu = 0;
            }

            if (!deu || (int)st.size() != c-1) {
                p(-1);
                return 0;
            }
            ans.pb(u);
        }
    }

    pv(ans);
}
