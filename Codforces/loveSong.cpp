//codeforces.com/contest/1539/problem/B

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

#define maxn 112345

int freq[maxn][26];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, q; cin >> n >> q;
    string s; cin >> s;

    fr(i, n) {
        if (i) fr(j, 26) freq[i][j] = freq[i-1][j];
        freq[i][s[i]-'a']++;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        // ll ans = n - (r-l+1);
        ll ans = 0;
        fr(c, 26) {
            ll amt = freq[r][c];
            if (l) amt -= freq[l-1][c];
            ans += amt*(c+1);
        }
        p(ans);
    }
}
