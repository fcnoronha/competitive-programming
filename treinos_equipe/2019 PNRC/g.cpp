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

int dist2(pii a, pii b) {
    return (a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s);
}

int main() {
    fastio;

    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);

    int ans = INT_MAX;
    if (x1 <= x && x <= x2) {
        if (y <= y1) ans = min(ans, (y1-y)*(y1-y));
        if (y >= y2) ans = min(ans, (y-y2)*(y-y2));
    }
    else if (y1 <= y && y <= y2) {
        if (x <= x1) ans = min(ans, (x1-x)*(x1-x));
        if (x >= x2) ans = min(ans, (x-x2)*(x-x2));
    }
    else {
        ans = min(ans, dist2({x,y}, {x1, y1}));
        ans = min(ans, dist2({x,y}, {x1, y2}));
        ans = min(ans, dist2({x,y}, {x2, y1}));
        ans = min(ans, dist2({x,y}, {x2, y2}));
    }

    cout << setprecision(3) << fixed << sqrt(ans) << endl;
}