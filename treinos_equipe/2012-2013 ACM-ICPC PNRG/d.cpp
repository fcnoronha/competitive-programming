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

#define maxn 50009;

int n, w, h;
vector<pii> pts;
bool printa;

int orientation(pii p1, pii p2, pii p3){

    int val = (p2.s - p1.s) * (p3.f - p2.f) -
              (p2.f - p1.f) * (p3.s - p2.s);

 	return val;
}

int check(pii a) {

    pii b = {w/2, h/2};

    vector<pii> l1, l2, md;
    fr(i, n) {
        int ori = orientation(a, pts[i], b);
        if (ori > 0) l1.pb(pts[i]);
        else if (ori < 0) l2.pb(pts[i]);
        else md.pb(pts[i]);
    }

    // dbg (n);
    // dbg(md.size());

    int aux = n/2;
    while (md.size() && l1.size() < aux) {
        l1.pb(md[md.size()-1]);
        md.pop_back();
    }
    while (md.size() && l2.size() < aux) {
        l2.pb(md[md.size()-1]);
        md.pop_back();
    }

    if (printa)
        for (auto x : l1)
            cout << x.f/2 << " " << x.s/2 << "\n";

    return abs(int(l2.size()-l1.size()));
}

int main(){
    fastio

    while (cin >> n >> w >> h && (n || w || h)) {

        printa = 0;
        h *= 2; w *= 2;
        pts.clear();

        vector<pii> v1, v2;

        int x, y;
        fr(i, n) {
            cin >> x >> y;
            x*=2; y*=2;
            pts.pb({x,y});

            if (2*y > h) v1.pb({x,y});
            v2.pb({x,y});
        }

        sort(all(v1));
        sort(all(v2));

        int lo = -1, hi = v1.size()-1, mid;
        while (hi - lo > 1){
            mid = (hi + lo)/2;
            if (check(v1[lo]) <= check(v1[hi]))
                hi = mid;
            else
                lo = mid;
        }

        if (v1.size() && check(v1[lo]) == 0) {
            printa = 1;
            check(v1[lo]);
            continue;
        }

        lo = -1, hi = v2.size()-1, mid;
        while (hi - lo > 1){
            mid = (hi + lo)/2;
            if (check(v2[lo]) <= check(v2[hi]))
                hi = mid;

            else
                lo = mid;
        }

        if (v2.size() && check(v2[lo+1]) == 0) {
            printa = 1;
            check(v2[lo+1]);
            continue;
        }
    }
}
