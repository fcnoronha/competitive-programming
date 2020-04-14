//codeforces.com/contest/1335/problem/E1

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
        int v[n];
        fr(i, n) cin >> v[i];

        int pre_sm[n+4][27], suf_sm[n+4][27];
        fr(i, n+4) fr(j, 27) pre_sm[i][j] = suf_sm[i][j] = 0;
        
        fr(i, n) {
            pre_sm[i+1][v[i]]++;
            fr(j, 27) pre_sm[i+1][j] += pre_sm[i][j];
        }
        for (int i = n-1; i >= 0; i--) {
            suf_sm[i+1][v[i]]++;
            fr(j, 27) suf_sm[i+1][j] += suf_sm[i+2][j]; 
        }

        int ans = 0;
        fr(j, 27) ans = max(ans, pre_sm[n][j]);

        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {

                int mx_mid = 0, mx_pts = 0;
                fr(j, 27) {
                    mx_mid = max(mx_mid, pre_sm[r][j] - pre_sm[l-1][j]);
                    int aux = min(pre_sm[l-1][j], suf_sm[r+1][j]);
                    mx_pts = max(mx_pts, aux);
                }

                ans = max(ans, mx_mid + 2*mx_pts);
            }
        }

        p(ans);
    }
}
