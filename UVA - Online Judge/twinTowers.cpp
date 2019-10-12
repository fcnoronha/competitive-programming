//onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1007

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

    int h,k, to = 0;
    while (cin >> h >> k && (h || k)) {


        int b1[h], b2[k];
        fr(i, h) cin >> b1[i];
        fr(i, k) cin >> b2[i];

        int memo[h+3][k+4];
        fr(i, h+1)
            fr(j, k+1) {

                if (i == 0 || j == 0) {
                    memo[i][j] = 0;
                    continue;
                }

                if (b1[i-1] == b2[j-1]) {
                    memo[i][j] = memo[i-1][j-1] + 1;
                    continue;
                }

                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }

        to++;
        cout << "Twin Towers #" << to;
        cout << "\nNumber of Tiles : " << memo[h][k] << "\n\n";
    }
}
