//codeforces.com/contest/1342/problem/D

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

    ll n, k;
    cin >> n >> k;

    vl m(n);
    fr(i, n) cin >> m[i];
    sort(all(m)); reverse(all(m));

    vl c(k+1, 0ll);
    frr(i, k) cin >> c[i];

    ll amt = 0ll, ans = 0;
    for (auto x: m) {
        amt++;
        ans = max(ans, (amt+c[x]-1)/c[x]);
    }

    p(ans);
    vl oi[ans];
    fr(i, n) oi[i%ans].pb(m[i]);
    fr(i, ans) {
        cout << oi[i].size() << " ";
        for (auto x: oi[i]) cout << x << " ";
        cout << endl;
    }
}
