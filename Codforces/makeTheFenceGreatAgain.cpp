//codeforces.com/contest/1221/problem/D

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

#define maxn 300009

ll pd[maxn][3];

int main() {
    fastio;

    int q;
    cin >> q;
    while (q--) {

        int n;
        cin >> n;
        pll v[n];
        fr(i, n) cin >> v[i].f >> v[i].s;

        pd[0][0] = 0ll;
        pd[0][1] = v[0].s;
        pd[0][2] = 2ll*v[0].s;

        for (int i = 1; i < n; i++) {
            int h = v[i].f;
            ll cst = v[i].s;

            fr(j, 3) {

                pd[i][j] = LINF;
                int nh = h+j;
                fr(k, 3) {

                    int nnh = k+v[i-1].f;
                    if (nh == nnh) continue;
                    pd[i][j] = min(pd[i][j], (j*cst)+pd[i-1][k]);
                }
            }
        }

        p(min({pd[n-1][0], pd[n-1][1], pd[n-1][2]}));
    }
}
