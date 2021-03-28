//codeforces.com/contest/1499/problem/C

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

    int t;
    cin >> t;
    while (t--) {

        ll n;
        cin >> n;

        ll c[n];
        fr(i, n) cin >> c[i];

        ll acc[n];
        acc[0] = c[0];
        for (int i = 1; i < n; i++) acc[i] = acc[i-1]+c[i];

        ll ans = acc[1]*n;
        multiset<ll> st1, st2;
        st1.insert(c[0]);
        st2.insert(c[1]);

        for (int i = 3; i <= n; i++) {

            if (i%2) st1.insert(c[i-1]);
            else     st2.insert(c[i-1]);

            ll mn1 = *st1.begin(); st1.erase(st1.find(mn1));
            ll mn2 = *st2.begin(); st2.erase(st2.find(mn2));

            ll sh = st1.size();
            ll sv = st2.size();
            // dbg(sh); dbg(sv);

            ll aux = (acc[i-1]-mn1-mn2);
            aux   += (n-sh)*mn1;
            aux   += (n-sv)*mn2;

            ans = min(ans, aux);
            st1.insert(mn1);
            st2.insert(mn2);
        }

        p(ans);
    }
}
