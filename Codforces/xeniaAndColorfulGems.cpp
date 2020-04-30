//codeforces.com/contest/1337/problem/D

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

ll ans;

void solve(vl &r, vl &b, vl &g) {
    fr(i, r.size()) {
        auto ig = lower_bound(all(g), r[i]);
        auto ib = upper_bound(all(b), r[i]);
        if (ig == g.end() || ib == b.begin()) continue;
        ib--;
        ll x = r[i], y = *ig, z = *ib;
        ans = min(ans, (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x));
    }
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        vl v[3] = {vl(nr), vl(ng), vl(nb)};
        fr(i, nr) cin >> v[0][i];
        fr(i, ng) cin >> v[1][i];
        fr(i, nb) cin >> v[2][i];

        sort(all(v[0]));
        sort(all(v[1]));
        sort(all(v[2]));
    
        ans = LLONG_MAX;
        int oi[3] = {0,1,2};
        do {
            solve(v[oi[0]], v[oi[1]], v[oi[2]]);
        } while (next_permutation(oi, oi+3));

        p(ans);
    }
}
