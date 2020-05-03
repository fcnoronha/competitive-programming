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

#define maxn 112345

int id[maxn], q_ans[maxn], tm_q[maxn];
set<int> cmp[maxn];
vi porra;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;

        frr(i, n) {
            id[i] = i;
            cmp[i].clear();
            cmp[i].insert(i);
        }

        vector<pair<pii, int>> joins;
        int q_idx = 0;
        frr(i, m) {
            int op, u, v;
            cin >> op >> u >> v;
            if (op == 1) {
                joins.pb({{u, v}, i});
            }
            else {
                cmp[u].insert(-q_idx);
                cmp[v].insert(-q_idx);
                tm_q[q_idx++] = i;
            }
        }
        
        fr(i, q_idx) q_ans[i] = -1;

        for (auto j: joins) {

            int u = j.f.f, v = j.f.s;
            u = id[u];
            v = id[v];
            int tm = j.s;
            if (u == v) continue;
        
            if (cmp[u].size() < cmp[v].size()) swap(u, v);
            int n_id = u;

            for (int x: cmp[v]) {
                if (x > 0) {
                    id[x] = n_id;
                    cmp[u].insert(x);                
                    continue;
                }
                if (cmp[u].count(x)) {
                    cmp[u].erase(x);
                    int idx = abs(x);
                    q_ans[idx] = tm;
                    continue;
                }
                cmp[u].insert(x);
            }
            cmp[v].clear();
        }

        fr(i, q_idx) {
            if (tm_q[i] >= q_ans[i]) p(q_ans[i]);
            else p(-1);
        }
    }
}