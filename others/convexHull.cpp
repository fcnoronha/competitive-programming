//open.kattis.com/problems/convexhull

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

// Graham-Scan to find convex hull in O(nlogn)

typedef pair<int,int> point;
#define x first
#define y second

int is_left(point a, point b, point c) {
    int det = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
    if (det > 0) return 1;  // left
    if (det < 0) return -1; // right
    return 0;               // collinear
}

vector<point> ch(vector<point> pt) {

    sort(all(pt));
    pt.erase(unique(all(pt)), pt.end());

    // corner
    int n = pt.size();
    if (n == 1) return pt;

    vector<point> h = {pt[0]};
    for (int i = 1; i < n; i++) {
        while (h.size() >= 2 && is_left(h[h.size()-2], h[h.size()-1], pt[i]) <= 0) 
            h.pop_back();
        h.pb(pt[i]);
    }
    int sz = h.size();
    for (int i = n-2; i >= 0; i--) {
        while (h.size()-sz >= 1 && is_left(h[h.size()-2], h[h.size()-1], pt[i]) <= 0) 
            h.pop_back();
        h.pb(pt[i]);
    }
    h.pop_back();
    
    return h;     
}

int main() {
    fastio;

    int n;
    while (cin >> n && n) {

        vector<point> pt;
        fr(i, n) {
            int x, y;
            cin >> x >> y;
            pt.pb({x,y});
        }

        auto ans = ch(pt);
        cout << ans.size() << endl;
        for (auto x: ans)
            cout << x.f << " " << x.s << endl; 
    }
}
