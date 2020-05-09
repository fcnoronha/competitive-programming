//codeforces.com/contest/1342/problem/B

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
        string s;
        cin >> s;
        int n = s.size(), no = 0;
        for (auto c: s) if (c == '1') no++;

        if (no == n || no == 0) {
            p(s);
            continue;
        }

        string ans;

        int k = (n+no-1)/no, nz = n-no, kz = (n+nz-1)/nz;

        if (k < kz) {
            fr(i, 2*n) {
                if (i%k) ans += '0';
                else ans += '1';
            }
        }
        else {
            fr(i, 2*n) {
                if (i%kz) ans += '1';
                else ans += '0';
            }
        }

        p(ans);
    }
}
