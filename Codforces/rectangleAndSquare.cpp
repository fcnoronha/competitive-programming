//codeforces.com/contest/135/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i].idx << " \n"[i==x.size()-1]

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
	ll x, y, idx;
	point() { x = y = 0; }
	point(ll _x, ll _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
		return idx < other.idx;
	}
	point operator +(point other) const {
		return point(x + other.x, y + other.y);
	}
	point operator -(point other) const {
		return point(x - other.x, y - other.y);
	}
    ll operator *(point other) const {
        return (x*other.x + y*other.y);
    }
};

// distance between two points
double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main(){
    fastio

    vector<point> pt(8);
    int cnt = 1;
    for (auto &p : pt)
        cin >> p.x >> p.y, p.idx = cnt++;

    int oi = 0;
    fr(perm, 1<<8) {

        if (__builtin_popcount(perm) != 4) continue;

        vector<point> square, retang;
        fr(i, 8) {
            if (perm & (1<<i)) square.pb(pt[i]);
            else retang.pb(pt[i]);
        }

        sort(all(square));

        // trying to form a square
        do {

            // not retangle
            if ((square[1]-square[0])*(square[2]-square[0]) ||
                (square[2]-square[3])*(square[1]-square[3]))
                continue;

            ll d1 = dist(square[0], square[1]);
            ll d2 = dist(square[0], square[2]);
            ll d3 = dist(square[2], square[3]);
            ll d4 = dist(square[3], square[1]);

            // not a square
            if (d1 != d2 || d1 != d3 || d1 != d4)
                continue;

            sort(all(retang));
            // trying to form a retangle
            do {

                // not retangle
                if ((retang[1]-retang[0])*(retang[2]-retang[0]) ||
                    (retang[2]-retang[3])*(retang[1]-retang[3]))
                    continue;

                p("YES");
                pv(square);
                pv(retang);
                return 0;

            } while (next_permutation(all(retang)));

        } while (next_permutation(all(square)));
    }

    p("NO");
}
