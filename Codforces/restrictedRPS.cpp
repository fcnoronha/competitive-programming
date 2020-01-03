//codeforces.com/contest/1245/problem/B

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

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int r, p, s;
        cin >> r >> p >> s;

        int cnt = 0;

        string str;
        cin >> str;

        string ans;

        fr(i, n) {

            int c = str[i];

            if (c == 'R') {
                if (p) {
                    ans += "P";
                    p--;
                    cnt++;
                    continue;
                }
                ans += "#";
            }
            if (c == 'P') {
                if (s) {
                    ans += "S";
                    s--;
                    cnt++;
                    continue;
                }
                ans += "#";
            }
            if (c == 'S') {
                if (r) {
                    ans += "R";
                    r--;
                    cnt++;
                    continue;
                }
                ans += "#";
            }
        }

        if (cnt < (n+1)/2) {
            p("NO");
            goto fim;
        }

        fr(i, n) {
            if (ans[i] != '#') continue;
            if (p) ans[i] = 'P', p--;
            else if (r) ans[i] = 'R', r--;
            else if (s) ans[i] = 'S', s--;
        }

        p("YES");
        p(ans);

        fim:;
    }
}
