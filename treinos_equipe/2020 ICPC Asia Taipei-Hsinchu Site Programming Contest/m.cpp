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

bool set_eq(set<int> a, set<int> b) {
    if (a.size() != b.size()) return false;
    for (auto x: a) if (b.find(x) == b.end()) return false;
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t; cin >> t;
    while (t--) {

        int nc, nr;
        cin >> nc >> nr;

        set<int> col;
        set<int> row;
        fr(i, nc) {
            int x; cin >> x;
            col.insert(x);
        }
        fr(i, nr) {
            int x; cin >> x;
            row.insert(x);
        }

        int ans = 0;
        vector<pii> v({{0,0}, {0,1}, {1,0}, {1,1}});
        for (int i = 0; i < 4; i++) {

            set<int> c4, r4;
            c4.insert(v[i].f);
            r4.insert(v[i].s);
            ans += set_eq(c4, col) && set_eq(r4, row);

            for (int j = i+1; j < 4; j++) {

                set<int> c1, r1;
                c1.insert(v[i].f);
                c1.insert(v[j].f);
                r1.insert(v[i].s);
                r1.insert(v[j].s);
                ans += set_eq(c1, col) && set_eq(r1, row);

                for (int k = j+1; k < 4; k++) {

                    set<int> c2, r2;
                    c2.insert(v[i].f);
                    c2.insert(v[j].f);
                    c2.insert(v[k].f);
                    r2.insert(v[i].s);
                    r2.insert(v[j].s);
                    r2.insert(v[k].s);
                    ans += set_eq(c2, col) && set_eq(r2, row);

                    for (int l = k+1; l < 4; l++) {

                        set<int> c3, r3;
                        c3.insert(v[i].f);
                        c3.insert(v[j].f);
                        c3.insert(v[k].f);
                        c3.insert(v[l].f);
                        r3.insert(v[i].s);
                        r3.insert(v[j].s);
                        r3.insert(v[k].s);
                        r3.insert(v[l].s);
                        ans += set_eq(c3, col) && set_eq(r3, row);

                    }

                }

            }
        }

        p(ans);
    }
}
