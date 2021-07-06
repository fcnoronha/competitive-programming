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

    int n; cin >> n;

    ll c[n]; fr(i, n) cin >> c[i];

    string s[n], rs[n];
    fr(i, n) {
        cin >> s[i];
        rs[i] = s[i];
        reverse(all(rs[i]));
    }

    ll memo[n][2];
    memo[0][0] = 0;
    memo[0][1] = c[0];

    for (int i = 1; i < n; i++) {

        ll &pd = memo[i][0];
        ll &pdr = memo[i][1];
        pd = pdr = LINF;

        if (s[i-1] <= s[i]) {
            pd = min(pd, memo[i-1][0]);
        }

        if (s[i-1] <= rs[i]) {
            pdr = min(pdr, memo[i-1][0] + c[i]);
        }

        if (rs[i-1] <= s[i]) {
            pd = min(pd, memo[i-1][1]);
        }

        if (rs[i-1] <= rs[i]) {
            pdr = min(pdr, memo[i-1][1] + c[i]);
        }
    }

    ll ans = min(memo[n-1][0], memo[n-1][1]);
    if (ans == LINF) ans = -1;
    p(ans);
}
