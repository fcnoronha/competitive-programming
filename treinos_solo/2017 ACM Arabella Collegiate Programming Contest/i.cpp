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

char lt[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
bool top[26];

int main() {
    fastio;

    int t;
    cin >> t;

    fr(i, 11) top[lt[i]-'A'] = 1; 

    while (t--) {

        string s;
        cin >> s;
        int ans = 0, n = s.size();

        fr(i, n) {
            if (!top[s[i]-'A']) continue;
            ans = max(ans, 1);
            int l = i-1, r = i+1;
            while (1) {
                if (l < 0) break;
                if (r >= n) break;
                if (s[l] != s[r]) break;
                if (!top[s[l]-'A']) break;
                ans = max(ans, r-l+1);
                l--;
                r++;
            }

            l = i, r = i+1;
            while (1) {
                if (l < 0) break;
                if (r >= n) break;
                if (s[l] != s[r]) break;
                if (!top[s[l]-'A']) break;
                ans = max(ans, r-l+1);
                l--;
                r++;
            }

            l = i-1, r = i;
            while (1) {
                if (l < 0) break;
                if (r >= n) break;
                if (s[l] != s[r]) break;
                if (!top[s[l]-'A']) break;
                ans = max(ans, r-l+1);
                l--;
                r++;
            }
        }

        p(ans);
    }
}
