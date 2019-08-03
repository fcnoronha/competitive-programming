//codeforces.com/contest/961/problem/D

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

struct point {
	ll x, y;
	point() { x = y = 0.0; }
	point(ll _x, ll _y) : x(_x), y(_y) {}
    point operator -(point other) const {
        return point(x - other.x, y - other.y);
    }
};

ll cross(point p1, point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}

bool collinear(point p, point q, point r) {
	return cross(p-q, r-p) == 0ll;
}

int main(){
    fastio

    int n;
    cin >> n;

    vector<point> pt, l1;
    fr(i, n) {
        ll x, y;
        cin >> x >> y;

        pt.pb(point(x, y));
    }
    if (n <= 3) {
        p("YES");
        return 0;
    }

    for (auto se : {pii{0,1}, pii{0,2}, pii{1,2}}) {

        int start = se.f;
        int end = se.s;
        l1.clear();

        // checking with line p[start]-p[end];
        fr(i, n) {
            if (collinear(pt[start], pt[end], pt[i])) continue;
            l1.pb(pt[i]);
        }

        if (l1.size() <= 2) {
            p("YES");
            return 0;
        }

        bool check = 1;
        for (auto p : l1)
            if (!collinear(l1[0], l1[1], p))
                check = 0;

        if (check) {
            p("YES");
            return 0;
        }

        l1.clear();
    }

    p("NO");
}
