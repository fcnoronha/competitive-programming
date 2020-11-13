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

int n, m;
vi tgt;
map<vi, bool> mp;

bool solve(vi &v, bool opa) {
    
    if (mp.find(v) != mp.end()) return mp[v];
    if (v == tgt) return 1;
    if (v.size() < m || v.size() == 1) return 0;

    fr(i, (int)v.size()) {

        if (i == 0 && !opa) continue;
        vi l, r;
        fr(k, i) l.pb(v[k]);
        for (int k = i; k < (int)v.size(); k++) r.pb(v[k]);
        reverse(all(r));

        if (l.size() < r.size()) swap(l, r);
        int ll = ((int)l.size())-1, rr = ((int)r.size())-1;
        while (rr >= 0) l[ll--] += r[rr--];
        
        if (solve(l, (i>0))) {
            mp[l] = 1;
            return 1;
        }
        else mp[l] = 0;
    }

    mp[v] = 0;
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    cin >> n;
    vi v(n);
    fr(i, n) cin >> v[i];

    cin >> m;
    tgt = vi(m);
    fr(i, m) cin >> tgt[i];

    if (solve(v, 1)) p("S");
    else          p("N");
}
