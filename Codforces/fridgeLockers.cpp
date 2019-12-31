//codeforces.com/contest/1255/problem/B

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

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<pii> a;
        frr(i, n) {
            int ai;
            cin >> ai;
            a.pb({ai, i});
        }
        sort(all(a));

        if (n == 2 || m < n) {
            p("-1");
            continue;
        }

        vector<pii> ans;
        int cst = 0;
        if ((n-2)*2 <= m) {

            for (int i = 2; i < n; i++) {

                ans.pb({a[0].s, a[i].s});
                ans.pb({a[1].s, a[i].s});

                cst += a[i].f*2 + a[0].f + a[1].f;
                m -= 2;
            }

            while (m--) {
                ans.pb({a[0].s, a[1].s});
                cst += a[0].f + a[1].f;
            }

            cout << cst << endl;
            for (auto x: ans) 
                cout << x.f << " " << x.s << endl;

            continue;
        }

        fr(i, n) {
            ans.pb({a[i].s, a[(i+1)%n].s});
            cst += a[i].f + a[(i+1)%n].f;
            m--;
        }

        while (m--) {
            ans.pb({a[0].s, a[1].s});
            cst += a[0].f + a[1].f;
        }

        cout << cst << endl;
        for (auto x: ans) 
            cout << x.f << " " << x.s << endl;
    }
}
