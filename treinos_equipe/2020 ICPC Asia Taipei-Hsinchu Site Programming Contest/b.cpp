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

    vi v(4);
    fr(i, 4) cin >> v[i];

    set<int> ans;
    vector<pair<int, int>> op({ {3,'m'}, {3,'m'}, {2,'x'}, {2,'x'}, {2,'x'}, {1,'-'}, {1,'-'}, {1,'-'}, {1,'+'}, {1,'+'}, {1,'+'} });

    vi perm(4); fr(i, 4) perm[i] = i;

    do {

        vi vv(4);
        fr(i, 4) vv[i] = v[perm[i]];

        fr(bit, 1<<11) {

            if (__builtin_popcount(bit) != 3) continue;

            vector<pair<int, int>> aux;
            fr(i, 12) 
                if (bit & (1<<i)) 
                    aux.pb(op[i]);

            vi p2(3); fr(i, 3) p2[i] = i;

            do {

                vector<pair<int, int>> auxx(3);
                fr(i, 3) auxx[i] = aux[p2[i]];

                // dbg(aux.size()); continue;
                vector<pair<int, int>> eq;
                eq.pb({0, vv[0]});
                fr(i, 3) {
                    eq.pb(auxx[i]);
                    eq.pb({0, vv[i+1]});
                }

                fr(oiii, 3) {

                    int bst = 0, nn = eq.size();
                    fr(i, nn) 
                        if (eq[i].f > eq[bst].f)
                            bst = i;

                    vector<pair<int, int>> neq;
                    for (int i = 0; i <= bst-2; i++) neq.pb(eq[i]);

                    int ant = eq[bst-1].s, pst = eq[bst+1].s;
                    if (eq[bst].s == 'm') {
                        neq.pb({0, stoi( to_string(ant) + to_string(pst) )});
                    }

                    if (eq[bst].s == 'x') {
                        neq.pb({0, ant*pst});
                    }

                    if (eq[bst].s == '-') {
                        neq.pb({0, ant-pst});
                    }

                    if (eq[bst].s == '+') {
                        neq.pb({0, ant+pst});
                    }

                    for (int i = bst+2; i < nn; i++) neq.pb(eq[i]);

                    // for (auto x: neq) cout << x.f << ' ';
                    // cout << endl;
                    eq = neq;
                    // goto fim;
                }

                if (eq[0].s < 0) continue;
                ans.insert(eq[0].s);

                // goto fim;
            }while (next_permutation(all(p2)));
        }

    } while (next_permutation(all(perm)));

    // for (auto x: ans) dbg(x);

    fim:;
    p(ans.size());
}
