//codeforces.com/contest/1399/problem/C

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int w[n];
        fr(i, n) cin >> w[i];

        int ans = 0;
        frr(s, 2*n) {
            map<int, int> mp;
            fr(i, n) mp[w[i]]++;
            int cnt = 0;
            fr(i, n) {
                if (mp[w[i]] && mp[s-w[i]]) {
                    if (s == w[i]+w[i] && mp[w[i]] < 2) continue;
                    mp[s-w[i]]--;
                    mp[w[i]]--;
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }

        p(ans);
    }
}
