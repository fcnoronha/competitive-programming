//codeforces.com/contest/1296/problem/C

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
        string s;

        cin >> n >> s;

        int sz = INF;
        pii ans = {INF, INF};
        map<pii, int> mp;

        int x = 0, y = 0;
        frr(i, n) {

            mp[{x, y}] = i;

            if (s[i-1] == 'U') y++;
            else if (s[i-1] == 'D') y--;
            else if (s[i-1] == 'R') x++;
            else x--;
                
            if (mp[{x, y}] != 0) {

                int delta = i - mp[{x,y}];

                if (delta < sz) {
                    sz = delta;
                    ans = {mp[{x,y}], i};
                }
            }
        }

        if (sz == INF) p("-1");
        else cout << ans.f << " " << ans.s << endl;
    }
}
