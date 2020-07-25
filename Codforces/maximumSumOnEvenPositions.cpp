//codeforces.com/contest/1373/problem/D

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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
    fastio;

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ll a[n];
        fr(i, n) cin >> a[i];

        ll ans = 0ll;
        fr(i, n) {
            if (i%2) continue;
            ans += a[i];
        }

        vl aux;
        for (int i = 1; i+1 < n; i += 2)  
            aux.pb(a[i]-a[i+1]);
        pll mx = {0, 0}, cur = {0, 0};
        fr(i, aux.size()) {
            if (cur.f <= 0) cur = {0, i};
            cur.f += aux[i];
            mx = max(mx, cur);
        }
        ll a1 = ans+mx.f;

        aux.clear();
        for (int i = 1; i < n; i += 2)  
            aux.pb(a[i]-a[i-1]);
        mx = {0, 0}, cur = {0, 0};
        fr(i, aux.size()) {
            if (cur.f <= 0) cur = {0, i};
            cur.f += aux[i];
            mx = max(mx, cur);
        }
        ans = max({ans, ans+mx.f, a1});

        p(ans);
    }
}
