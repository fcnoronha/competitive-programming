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

    int t;
    cin >> t;
    frr(tt, t) {

        int x, y;
        cin >> x >> y;

        string s;
        cin >> s;

        int n = s.size();
        int pdm[n][2];
        ms(pdm, 0);

        // 0==C   1 ==J

        // p("");
        // dbg(s);
        fr(i, n) {
            // dbg(i);

            if (i == 0) continue;

            if (s[i] != '?') {

                if (s[i-1] != '?') {
                    // p("aaa");
                    pdm[i][0] = pdm[i][1] = pdm[i-1][0];
                    if (s[i-1] == 'J' && s[i] == 'C') pdm[i][0] = pdm[i][1] = pdm[i-1][0] + y;
                    if (s[i-1] == 'C' && s[i] == 'J') pdm[i][0] = pdm[i][1] = pdm[i-1][0] + x;
                    continue;
                }

                if (s[i] == 'C') {
                    // p("bbb");
                    pdm[i][0] = pdm[i][1] = min(pdm[i-1][1]+y, pdm[i-1][0]);
                    continue;
                }

                if (s[i] == 'J') {
                    // p("ccc");
                    pdm[i][0] = pdm[i][1] = min(pdm[i-1][1], pdm[i-1][0]+x);
                    continue;
                }
            }

            if (s[i-1] == '?') {
                // p("ddd");
                pdm[i][0] = min(pdm[i-1][0], pdm[i-1][1]+y);
                pdm[i][1] = min(pdm[i-1][1]+y, pdm[i-1][1]);
                continue;
            }

            if (s[i-1] == 'C') {
                // p("eee");
                pdm[i][0] = pdm[i-1][0];
                pdm[i][1] = pdm[i-1][0]+x;
                continue;
            }

            if (s[i-1] == 'J') {
                // p("fff");
                pdm[i][0] = pdm[i-1][0]+y;
                pdm[i][1] = pdm[i-1][0];
            }
        }

        // fr(i, n) cout << pdm[i][0] << " \n"[i==n-1];
        // fr(i, n) cout << pdm[i][1] << " \n"[i==n-1];
        // p("'----------'");

        cout << "Case #" << tt << ": " << min(pdm[n-1][0], pdm[n-1][1]) << endl;
    }
}
