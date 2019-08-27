//codeforces.com/contest/1207/problem/B

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main(){
    fastio

    int n, m;
    cin >> n >> m;

    int a[n][m], b[n][m];
    fr(i, n) fr(j, m) a[i][j] = b[i][j] = 0;

    fr(i, n) fr(j, m) cin >> a[i][j];

    vector<pii> ans;
    fr(i, n-1)
        fr(j, m-1)
            if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
                ans.pb({i,j});
                b[i][j] = b[i+1][j] = b[i][j+1] = b [i+1][j+1] = 1;
            }

    fr(i, n)
        fr(j, m) {
            if (a[i][j] != b[i][j]) {
                p("-1");
                return 0;
            }
        }

    p(ans.size());
    for (auto x : ans)
        cout << x.f+1 << " " << x.s+1 << "\n";
}
