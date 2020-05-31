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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds ;
typedef tree< pll, null_type,less< pll >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll solve(vector<pll> &v, ll t) {

    ll ans = 0ll, oi = 0ll;
    ordered_set q;
    for (auto x: v) {
        q.insert({x.s, oi++});
        if (x.f + x.s <= t) 
            ans = max(ans, (ll)q.order_of_key({t-x.f, INF}));
    }

    return ans;
}

int main() {
    fastio;

    ll a, b, t, ta, tb;
    cin >> a >> b >> t >> ta >> tb;

    ll c;
    cin >> c;
    vector<pll> itv;
    fr(i, c) {
        ll ai, bi;
        cin >> ai >> bi;

        ai = max(0ll, (ai-a)*ta);
        bi = max(0ll, (bi-b)*tb);
        itv.pb({ai, bi});
    }

    sort(all(itv));
    ll ans = solve(itv, t);

    for (auto &x: itv) swap(x.f, x.s);
    sort(all(itv));
    ans = max(ans, solve(itv, t));
   
    p(ans);
}
