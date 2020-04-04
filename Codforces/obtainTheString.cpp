//codeforces.com/contest/1295/problem/C

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

        string s, t;
        cin >> s >> t;

        vi pos[26], curi(26, 0);
        fr(i, s.size()) 
            pos[s[i]-'a'].pb(i);

        int ans = 1, mn = 0;
        fr(i, t.size()) {

            int c = t[i]-'a';
            if (pos[c].size() == 0) {
                p(-1);
                goto fim;
            }

            int idx = curi[c];
            if (idx == pos[c].size()) {
                fill(all(curi), 0);
                ans++;
                idx = mn = 0;
            }

            if (pos[c][idx] >= mn) {
                mn = pos[c][idx];
                curi[c]++;
                continue;
            }
            int ni = lower_bound(all(pos[c]), mn) - pos[c].begin();
            if (ni < pos[c].size()) {
                curi[c] = ni+1;
                mn = pos[c][ni];
            }
            else {
                fill(all(curi), 0);
                curi[c] = 1;
                mn = pos[c][0];
                ans++;
            }
        }

        p(ans);
        fim:;
    }
}
