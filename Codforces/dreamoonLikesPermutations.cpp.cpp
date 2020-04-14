//codeforces.com/contest/1330/problem/B

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

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vi v(n);
        fr(i, n) cin >> v[i];

        set<int> acum;
        vi ans, da_ida(n+2, 0), da_volta(n+2, 0);
        fr(i, n) {
            int cur = v[i];
            if (acum.count(-cur)) break;
            acum.insert(-cur);
            if (*acum.begin() == -acum.size()) 
                da_ida[i+1] = 1;
        }

        acum.clear();
        for (int i = n-1; i >= 0; i--) {
            int cur = v[i];
            if (acum.count(-cur)) break;
            acum.insert(-cur);
            if (*acum.begin() == -acum.size()) 
                da_volta[i+1] = 1;
        }

        //frr(i, n) cout << da_ida[i] << " \n"[i==n];
        //frr(i, n) cout << da_volta[i] << " \n"[i==n];

        frr(i, n) if (da_ida[i] && da_volta[i+1]) ans.pb(i);

        p(ans.size());
        for (auto x: ans) 
            cout << x << " " << n-x << endl;
    }
}
