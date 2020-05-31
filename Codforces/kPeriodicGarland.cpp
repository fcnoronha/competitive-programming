//codeforces.com/contest/1353/problem/E

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

    int tt;
    cin >> tt;
    while (tt--) { 

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ans = INF, c1 = 0;
        for (auto c: s) c1 += (c == '1');

        fr(ini, k) {

            string t;
            for (int i = ini; i < n; i += k) t += s[i];
            int tn = t.size();

            vi ac(tn);
            ac[0] = (t[0] == '1');
            frr(i, tn-1) ac[i] = ac[i-1] + (t[i]=='1');

            vi dp(tn);
            dp[0] = (t[0]!='1');
            frr(i, tn-1)
                dp[i] = min(ac[i-1], dp[i-1]) + (t[i] != '1');

            int aux = ac[tn-1];
            fr(i, tn)
                aux = min(aux, dp[i]+ac[tn-1]-ac[i]);
                
            ans = min(ans, c1 - ac[tn-1] + aux);
        }

        p(ans);
    }
}
