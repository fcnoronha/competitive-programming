//vjudge.net/contest/354794#problem/G

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

const double EPS = 1E-9;

struct pt {
    double x, y;
};

struct seg {
    pt p, q;
    int id;

    double get_y(double x) const {
        if (abs(p.x - q.x) < EPS) return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }
};

bool intersect1d(double l1, double r1, double l2, double r2) {
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);
    return max(l1, l2) <= (min(r1, r2) + EPS);
}

int vec(const pt& a, const pt& b, const pt& c) {
    double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (abs(s) < EPS) return 0;
    if (s > 0) return 1;
    else return -1;
}

bool intersect(const seg& a, const seg& b) {
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
           intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
           vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
           vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}

bool operator<(const seg &a, const seg &b){
    double x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    double ya = a.get_y(x);
    double yb = b.get_y(x);
    if (ya == yb) return a.id < b.id;
    return ya < (yb-EPS);
}

struct event {
    double x;
    int tp, id;

    event() {}
    event(double x, int tp, int id) : x(x), tp(tp), id(id) {}

    bool operator<(const event& e) const {
        if (abs(x - e.x) > EPS) return x < e.x;
        return tp > e.tp;
    }
};

set<seg> s;
#define seg_it set<seg>::iterator
vector<seg_it> where;

seg_it prev(seg_it it) {
    return it == s.begin() ? s.end() : --it;
}

seg_it next(seg_it it) {
    return ++it;
}

bool solve(vector<seg> &a) {
    int n = (int)a.size();
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(event(a[i].p.x, +1, i));
        e.push_back(event(a[i].q.x, -1, i));
    }
    sort(e.begin(), e.end());

    s.clear();
    where.resize(a.size());
    for (size_t i = 0; i < e.size(); i++) {
        int id = e[i].id;
        if (e[i].tp == +1) {
            seg_it nxt = s.lower_bound(a[id]), prv = prev(nxt);
            if (nxt != s.end() && intersect(*nxt, a[id]))
                if (abs(nxt->id - id) > 1 && abs(nxt->id - id) != n-1)
                    return 1;
            if (prv != s.end() && intersect(*prv, a[id]))
                if (abs(prv->id - id) > 1 && abs(prv->id - id) != n-1)
                    return 1;
            where[id] = s.insert(nxt, a[id]);
        }
        else {
            seg_it nxt = next(where[id]), prv = prev(where[id]);
            if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                if (abs(prv->id - nxt->id) > 1 && abs(prv->id - nxt->id) != n-1)
                    return 1;
            
            s.erase(where[id]);
        }
    }
    return 0;
}

int main() {
    fastio;

    int n;
    while (cin >> n && n) {

        vector<seg> segs;
        vector<pt> pts;
        fr(i, n) {
            int x, y;
            cin >> x >> y;
            pts.pb({double(x),double(y)});
        }
        
        fr(i, n) {
            seg aux = seg({pts[i], pts[(i+1)%n], i});
            if (aux.p.x > aux.q.x) swap(aux.p, aux.q);
            segs.pb(aux);
        }
        
        if (solve(segs)) p("NO");
        else p("YES");
    }
}
