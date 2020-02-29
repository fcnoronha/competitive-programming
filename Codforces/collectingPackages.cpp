//codeforces.com/contest/1294/problem/B

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
        vi pos(1010, -1);
        vi mn(1010, INF);
        vi amt(1010, 0);
        int x, y;
        fr(i, n) {
            cin >> x >> y;
            pos[x] = max(pos[x], y);
            mn[x] = min(mn[x], y);
            amt[x]++;
        }
        string ans;
        int cnt = 0, cury = 0;
        fr(i, 1010) {
            if (pos[i] == -1) {
                ans += 'R';
                continue;
            }
            if (mn[i] < cury) break;
            cnt += amt[i];
            int d = pos[i]-cury;
            cury = pos[i];
            fr(j, d) ans += 'U';
            if (cnt == n) break;
            ans += 'R';
        }

        if (cnt != n) {
            p("NO");
            continue;
        }
        p("YES");
        p(ans);
    }
}
