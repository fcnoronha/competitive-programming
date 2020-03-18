//codeforces.com/contest/339/problem/D

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

ll a[20][1<<18];

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    fr(i, (1<<n)) cin >> a[n][i];
    int par = !(n&1);

    for (int p = n-1; p >= 0; p--) {
        fr(i, (1<<p)) {
            if ((p&1) == par) a[p][i] = a[p+1][i<<1]|a[p+1][(i<<1)+1];
            else a[p][i] = a[p+1][i<<1]^a[p+1][(i<<1)+1];
        }
    }
    while (m--) {
        int p, b;
        cin >> p >> b;
        p--;
        a[n][p] = b;
        for (int i = n-1; i >= 0; i--, p >>= 1) {
            if ((i&1) == par) a[i][p>>1] = a[i+1][p] | a[i+1][p^1];
            else a[i][p>>1] = a[i+1][p] ^ a[i+1][p^1];
        }
        p(a[0][0]);
    }
}
