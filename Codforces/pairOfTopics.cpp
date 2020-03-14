//codeforces.com/contest/1324/problem/D

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

int main() {
    fastio;

    int n;
    cin >> n;
    ll a[n], b[n];
    fr(i, n) cin >> a[i];
    fr(i, n) cin >> b[i];

    ordered_set st;
    fr(i, n) {
        ll aux = b[i]-a[i];
        st.insert({aux, i});
    }

    ll ans = 0;
    fr(i, n) {
        ll aux = b[i]-a[i];
        st.erase({aux, i});
        aux = a[i]-b[i];
        ll amt = ll(st.order_of_key({aux, 0}));
        ans += amt;
    }

    p(ans);
}
