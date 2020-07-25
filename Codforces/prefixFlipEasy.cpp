//codeforces.com/contest/1382/problem/C1

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
        string as,bs;
        cin >> as >> bs;

        bool a[n], b[n];
        fr(i, n) a[i] = as[i]=='1';
        fr(i, n) b[i] = bs[i]=='1';

        vi ans;
        for (int i = n-1; i >= 0; i--) {
            if (a[i] == b[i]) continue;
            if (a[0] == b[i]) {
                ans.pb(1);
                a[0] = !a[0];
            }
            ans.pb(i+1);
            fr(j, i+1) a[j] = !a[j];
            reverse(a, a+i+1);
        }

        cout << ans.size() << " ";
        for (auto x: ans) cout << x << " ";
        cout << endl;
    }
}
