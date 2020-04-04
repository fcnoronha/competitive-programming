//codeforces.com/contest/1332/problem/A

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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2, dx, dy;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        dx = min(a, b); a -= dx, b -= dx;
        dy = min(c, d); c -= dy, d -= dy;

        if ((x-x1) < a) {
            p("NO");
            continue;
        }

        if (x2-x < b) {
            p("NO");
            continue;
        }

        if (y-y1 < c) {
            p("NO");
            continue;
        }

        if (y2-y < d) {
            p("NO");
            continue;
        }

        if (dx && x2-x == 0 && x-x1 == 0) {
            p("NO");
            continue;
        }

        if (dy && y2-y == 0 && y-y1 == 0){
            p("NO");
            continue;
        }

        p("YES");
    }
}
