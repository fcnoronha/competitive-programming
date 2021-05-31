#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    map<int, vector<char>> ans;

    vector<pair<int, int>> aux({ {'*', 4}, {'*', 4}, {'*', 4}, {'/', 4}, {'/', 4}, {'/', 4}, {'+', 2}, {'+', 2}, {'+', 2}, {'-', 2}, {'-', 2}, {'-', 2}});

    fr(bit, (1<<12)) {

        if (__builtin_popcount(bit) != 3) continue;

        vector<pair<int, int>> op;
        fr(i, 12) if (bit & (1<<i)) op.pb(aux[i]);
        // dbg(op.size());

        vector<int> perm({0,1,2});
        do {

            vector<pair<int, int>> v;
            vector<char> oper;
            
            v.pb({4,0});
            fr(i, 3) {
                v.pb(op[perm[i]]), v.pb({4,0});
                oper.pb(op[perm[i]].f);
            }

            fr(sahhusa, 3) {

                int mx = 0;
                fr(i, v.size()) if (v[i].s > v[mx].s) mx = i;

                vector<pii> nv;
                for (int i = 0; i < mx-1; i++) nv.pb(v[i]);

                if (v[mx].f == '/') {
                    if (v[mx+1].f == 0) goto fim;
                    nv.pb( {v[mx-1].f / v[mx+1].f, 0} );
                }
                if (v[mx].f == '*') nv.pb( {v[mx-1].f * v[mx+1].f, 0} );
                if (v[mx].f == '+') nv.pb( {v[mx-1].f + v[mx+1].f, 0} );
                if (v[mx].f == '-') nv.pb( {v[mx-1].f - v[mx+1].f, 0} );

                for (int i = mx+2; i < v.size(); i++) nv.pb(v[i]);

                v = nv;
            }

            // dbg(v[0].f);
            ans[v[0].f] = oper;

            fim:;
        } while (next_permutation(all(perm)));
    }

    int n; cin >> n;
    while (n--) {

        int x; cin >> x;

        if (ans.find(x) == ans.end()) {
            p("no solution");
            continue;
        }

        cout << "4 ";
        for (auto c: ans[x]) cout << c << " 4 ";
        cout << "= " << x << endl;
    }
}
