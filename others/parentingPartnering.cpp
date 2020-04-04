//codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9

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

int main() {
    fastio;
    int t;
    cin >> t;
    frr(tt, t) {

        int n;
        cin >> n;
        vector< pair<pii, int> > v;
        fr(i, n) {
            int s, e;
            cin >> s >> e;
            v.pb({{s, e}, i});
        }
        sort(all(v));

        vi ans(n, 0);
        int lst = 0;
        for (auto aux: v) {
            int ini = aux.f.f;
            int fim = aux.f.s;
            int idx = aux.s;
            if (ini < lst) continue;
            lst = fim;
            ans[idx]++;
        }

        string anss;
        fr(i, n) {
            if (ans[i]) anss += 'J';
            else anss += 'C';  
        }

        lst = 0;
        for (int i = 0; i < n; i++) {
            if (ans[v[i].s]) continue;

            int ini = v[i].f.f;
            int fim = v[i].f.s;
            if (ini < lst) {
                anss = "IMPOSSIBLE";
                break;
            }
            lst = fim;
        }

        cout << "Case #" << tt << ": " << anss << endl;
    }
}
