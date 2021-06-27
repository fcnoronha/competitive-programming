//codeforces.com/contest/1537/problem/C

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

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        vi v(n);
        fr(i, n) cin >> v[i];

        sort(all(v));
        
        int mn = INF, idx = 0;
        fr(i, n-1) if (v[i+1]-v[i] < mn) {
            mn = v[i+1]-v[i];
            idx = i;
        }

        vi ans;
        for (int i = idx+1; i < n; i++) ans.pb(v[i]);
        for (int i = 0; i <= idx; i++) ans.pb(v[i]);
        
        int c1 = 0, c2 = 0;
        fr(i, n-1) c1 += (ans[i]<=ans[i+1]);

        reverse(all(ans));
        fr(i, n-1) c2 += (ans[i]<=ans[i+1]);

        if (c2 < c1) reverse(all(ans));
        pv(ans);
    }
}
