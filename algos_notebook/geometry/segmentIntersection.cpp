// BENTLEY AND OTTMANN ALGORITHM FOR LINE INTERSECTION
// O(nlogn)
// Find first intersection

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

#define seg_it set<seg>::iterator

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

bool operator<(const seg& a, const seg& b) {
    double x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    return a.get_y(x) < (b.get_y(x) - EPS);
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
vector<seg_it> where;

seg_it prev(seg_it it) {
    if (it == s.begin()) return s.end();
    return --it;
}

seg_it next(seg_it it) {
    return ++it;
}

pair<int, int> solve(const vector<seg>& a) {
    int n = a.size();
    vector<event> e;
    for (int i = 0; i < n; i++) {
        e.pb(event(min(a[i].p.x, a[i].q.x), +1, i));
        e.pb(event(max(a[i].p.x, a[i].q.x), -1, i));
    }
    sort(all(e));

    s.clear();
    where.resize(n);
    for (int i = 0; i < e.size(); i++) {
        int id = e[i].id;
        if (e[i].tp == +1) {
            seg_it nxt = s.lower_bound(a[id]), prv = prev(nxt);
            if (nxt != s.end() && intersect(*nxt, a[id]))
                return {nxt->id, id};
            if (prv != s.end() && intersect(*prv, a[id]))
                return {prv->id, id};
            where[id] = s.insert(nxt, a[id]);
        }
        else {
            seg_it nxt = next(where[id]), prv = prev(where[id]);
            if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                return {prv->id, nxt->id};
            s.erase(where[id]);
        }
    }

    return {-1, -1};
}