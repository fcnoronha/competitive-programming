//codeforces.com/contest/1375/problem/C

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

        int n;
        cin >> n;

        int a[n];
        fr(i, n) cin >> a[i];

        vector<pii> v;
        int r = n-1, l = r-1;
        while (r >= 0) {
            int mn = a[r], mx = a[r];
            while (l >= 0 && a[l] < a[l+1]) {
                mn = min(mn, a[l]);
                mx = max(mx, a[l]);
                l--;
            }
            v.pb({mn, mx});
            r = l;
            l--;
        }

        int deu = 1;
        if (v.size() > 1 && v[0].s < v[v.size()-1].f) deu = 0;

        if (deu) p("YES");
        else p("NO");
    }
}