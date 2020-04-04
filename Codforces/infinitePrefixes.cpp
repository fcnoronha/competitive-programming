//codeforces.com/contest/1295/problem/B

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

        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;

        int cnt0 = 0, cnt1 = 0, tem = 0;
        vi blc(n, 0);
        fr(i, n) {
            cnt0 += s[i]=='0';
            cnt1 += s[i]=='1';

            blc[i] = cnt0-cnt1;
            tem += (blc[i] == x);
        }

        if (tem && cnt0 == cnt1) {
            p(-1);
            continue;
        }

        int ans = 0, blct = cnt0-cnt1;
        fr(i, n) 
            if (blct && (blc[i]-x)%blct == 0)
                ans += ( (blc[i]-x)/-blct ) >= 0;

        if (x == 0) ans++;
        p(ans);        
    }
}
