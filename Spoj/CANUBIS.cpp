//br.spoj.com/problems/CANUBIS/

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
	int x, y, z;
	point() { x = y = z = 0; }
	point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

	bool operator == (point other) const {
		return other.x == x && other.y == y && other.z == z;
	}

	point operator +(point other) const{
		return point(x + other.x, y + other.y, z + other.z);
	}

	point operator -(point other) const{
		return point(x - other.x, y - other.y, z - other.z);
	}

    bool operator < (point other) const {
        if (x != other.x) return x < other.x;
        else if (y != other.y) return y < other.y;
        else return z < other.z;
    }
};

point cross(point p1, point p2) {
	point ans;
	ans.x = p1.y*p2.z - p1.z*p2.y;
	ans.y = p1.z*p2.x - p1.x*p2.z;
	ans.z = p1.x*p2.y - p1.y*p2.x;
	return ans;
}

int main() {
    fastio

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<point, int> pt_cnt;
        vector<point> pt;

        int x, y, z;
        fr(i, n) {
            cin >> x >> y >> z;

            point aux = point(x, y, z);
            pt_cnt[aux]++;

            if (pt_cnt[aux] == 1)
                pt.pb(aux);
        }

        if (n <= 2) {
            p(n);
            continue;
        }

        int ans = 0;
        fr( i, pt.size() ) {

            point p = pt[i];
            ans = max(ans, pt_cnt[p]);

            fr( j, pt.size() ){

                if (j == 0) j = i+1;
                if (j == pt.size()) continue;

                point q = pt[j];

                // points in the plan formed by P,Q and R
                map<point, int> mp;

                for (auto r : pt) {

                    if (r == p || r == q)
                        continue;

                    point pq = q-p;
                    point pr = r-p;

                    point c = cross(pq, pr);

                    int g = __gcd(c.x, __gcd(c.y, c.z));

                    if (g != 0) c.x /= g, c.y /= g, c.z /= g;

                    mp[c] += pt_cnt[r];
                }

                int cnt = 0;
                for (auto x : mp)
                    cnt = max(cnt, x.s);

                cnt += pt_cnt[p] + pt_cnt[q];
                ans = max(ans, cnt);
            }
        }

        p(ans);
    }
}
