//codeforces.com/contest/1379/problem/C

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

        ll n, m;
        cin >> n >> m;

        pll v[m];
        vl a(m), ac(m);

        fr(i, m) {
            cin >> v[i].f >> v[i].s;
            a[i] = v[i].f;
        }

        sort(v, v+m), reverse(v, v+m);
        sort(all(a));

        for (int i = m-1; i >= 0; i--) {
            ac[i] = a[i];
            if (i < m-1) ac[i] += ac[i+1];
        }

        //fr(i, m) cout << ac[i] << " \n"[i == m-1];

        ll ans = 0ll;
        fr(i, m) {
            ans = max(ans, v[i].f + (n-1)*v[i].s);
            if (m-i <= n) ans = max(ans, ac[i]);

            if (upper_bound(all(a), v[i].s) == a.end()) continue;
            ll it = (upper_bound(all(a), v[i].s) - a.begin());
            //cout << "dupla: " << v[i].f << " " << v[i].s << " " << it << endl; 
            ll amt = m-it;
            if (amt+1 <= n && v[i].f <= v[i].s) 
                ans = max(ans, ac[it]+v[i].f+(n-amt-1)*v[i].s);
            if (amt <= n && v[i].f > v[i].s) 
                ans = max(ans, ac[it]+(n-amt)*v[i].s);
        }

        p(ans);
    }
}
