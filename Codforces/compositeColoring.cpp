//codeforces.com/contest/1332/problem/B

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

int lst[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vi a(n), col(n, -1);
        fr(i, n) cin >> a[i];

        set<int> used;
        fr(i, n) {
            fr(c, 11) {
                if (a[i]%lst[c] == 0) {
                    col[i] = c;
                    used.insert(c);
                    break;
                }
            }
        }

        int m = 1;
        map<int, int> mp;
        for (auto x: used) {
            mp[x] = m++;
        }
        for (auto &x: col) x = mp[x];
        p(m-1);
        pv(col);
    }
}
