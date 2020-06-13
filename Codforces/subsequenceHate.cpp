//codeforces.com/contest/1363/problem/B

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

#define maxn 1234
int cnt0[maxn], cnt1[maxn];

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
 
        string s;
        cin >> s;
        int n = s.size();
        ms(cnt0, 0); ms(cnt1, 0);

        cnt0[0] = (s[0] == '0');
        cnt1[0] = (s[0] == '1');
        for (int i = 1; i < n; i++) {
            cnt0[i] = cnt0[i-1] + (s[i] == '0');
            cnt1[i] = cnt1[i-1] + (s[i] == '1');
        }

        int ans = INF;
        fr(i, n) {
            ans = min(ans, cnt0[i] + (cnt1[n-1]-cnt1[i]));
            ans = min(ans, cnt1[i] + (cnt0[n-1]-cnt0[i]));
        }
        p(ans);
    }
}
