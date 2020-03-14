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

        ll a, b, n;
        cin >> a >> b >> n;

        vi cnt(10, 0);
        ll k = 1;
        while (1) {
            ll y = a*k*k + b*k;
            if (y > n) break;
            k++;
            vi freq(10, 0);
            while (y) {
                int d = y%10;
                y /= 10;
                freq[d]++;
            } 
            int mxf = 0;
            fr(k, 10) mxf = max(mxf, freq[k]);
            fr(k, 10) if (freq[k] == mxf) cnt[k]++;
        }

        int w = 0;
        fr(i, 10) w = max(w, cnt[i]);
        if (w == 0) {
            p(-1);
            continue;
        }
        fr(i, 10) {
            if (cnt[i] == w) {
                p(i);
                break;
            }
        }
    }
}
