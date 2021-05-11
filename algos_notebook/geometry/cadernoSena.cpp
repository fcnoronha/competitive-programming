// https://github.com/victorsenam/caderno/blob/master/code/geometry/algorithms.cpp

typedef double cood; cood eps = 1e-8; // risky: XXX, untested: TODO
const double pi = acos(-1.);


template<typename T> inline T sq(T x) { return x*x; }

struct vec {
    cood x, y;
    vec () : x(0), y(0) {} vec (cood a, cood b) : x(a), y(b) {}
    inline vec operator - (vec o) { return {x - o.x, y - o.y}; }
    inline vec operator + (vec o) { return {x + o.x, y + o.y}; }
    inline vec operator * (cood o) { return {x * o, y * o}; }
    inline vec operator / (cood o) { return {x / o, y / o}; }
    inline cood operator ^ (vec o) { return x * o.y - y * o.x; }
    inline cood operator * (vec o) { return x * o.x + y * o.y; }
    inline cood cross (vec a, vec b) { return ((*this)-a) ^ ((*this)-b); } // |(this)a||(this)b|sen(angle)
    inline cood inner (vec a, vec b) { return ((*this)-a) * ((*this)-b); } // |(this)a||(this)b|cos(angle)
    inline double angle (vec a, vec b) { return atan2(cross(a,b),inner(a,b)); } // ccw angle from (this)a to (this)b in range [-pi,pi]
    inline int ccw (vec a, vec b) { cood o = cross(a,b); return (eps < o) - (o < -eps); } // this is to the (1 left, 0 over, -1 right) of ab
    inline int dir (vec a, vec b) { cood o = inner(a,b); return (eps < o) - (o < -eps); } // a(this) is to the (1 same, 0 none, -1 opposite) direction of ab
    inline cood sq (vec o = vec()) { return inner(o,o); }
    inline double nr (vec o = vec()) { return sqrt(sq(o)); } //$
    inline vec operator ~ () { return (*this)/nr(); }
    inline vec proj (vec a, vec b) { return a + (b-a)*(a.inner((*this),b) / a.sq(b)); } // projects this onto line ab
    inline vec rotate (double a) { return vec(cos(a) * x - sin(a) * y, sin(a) * x + cos(a) * y); } // ccw by a radians
    inline vec rot90 () { return vec(-y,x); } // rotate(pi/2)$
    bool in_seg (vec a, vec b) { return ccw(a,b) == 0 && dir(a,b) <= 0; } // tips included
    double dist2_lin (vec a, vec b) { return a.sq(b) <= eps ? sq(a) : double(::sq(cross(a,b)))/a.sq(b); } // see cir.has_inter_lin
    double dist2_seg (vec a, vec b) { return a.dir((*this),b) == (b.dir((*this),a)) ? dist2_lin(a,b) : min(sq(a),sq(b)); }
    inline bool operator == (const vec & o) const { return abs(x-o.x) <= eps && abs(y-o.y) <= eps; }
    inline bool operator < (const vec & o) const { return (abs(x-o.x)>eps)?(x < o.x):(y > o.y); } // lex compare (inc x, dec y)
    // full ccw angle strict compare beginning upwards (this+(0,1)) around (*this)
    // incresing distance on ties, this is the first
    bool compare (vec a, vec b) { 
        if ((*this < a) != (*this < b)) return *this < b;
        int o = ccw(a,b); return o?o>0:((a == *this && !(a == b)) || a.dir(*this,b) < 0);
    }
}; //$

struct lin { // line
    vec p; cood c; // p*(x,y) = c
    lin () {} lin (vec a, cood b) : p(a), c(b) {}
    lin (vec s, vec t) : p((s-t).rot90()), c(p*s) {}
    inline lin parll (vec v) { return lin(p,v*p); }
    inline lin perp () { return lin(p.rot90(),c); }
    vec inter (lin o) { if (vec(0,0).ccw(p,o.p) == 0) throw 1; cood d = (p^o.p); return vec((c*o.p.y - p.y*o.c)/d,(o.c*p.x - o.p.x*c)/d); }
    bool contains (vec v) { return abs(p*v - c) <= eps; }
    vec at_x (cood x) { return vec(x,(c-p.x*x)/p.y); }
    vec at_y (cood y) { return vec((c-y*p.y)/p.x,y); }
    double sign_dist (vec v) { return double(p*v - c)/p.nr(); }
}; //$

struct cir { // circle
    vec c; cood r;
    cir () {} cir (vec v, cood d) : c(v), r(d) {}
    cir (vec u, vec v, vec w) { // XXX untreated degenerates
        vec mv = (u+v)/2; lin s(mv, mv+(v-u).rot90());
        vec mw = (u+w)/2; lin t(mw, mw+(w-u).rot90());
        c = s.inter(t); r = c.nr(u);
    }//$
    inline bool contains (vec w) { return c.sq(w) <= sq(r) + eps; } // border included
    inline bool border (vec w) { return abs(c.sq(w) - sq(r)) <= eps; }
    inline bool has_inter (cir o) { return c.sq(o.c) <= sq(r + o.r) + eps; } // borders included
    inline bool has_border_inter (cir o) { return has_inter(o) && c.sq(o.c) + eps >= sq(r - o.r); }
    inline bool has_inter_lin (vec a, vec b) { return a.sq(b) <= eps ? contains(a) : sq(c.cross(a,b)) <= sq(r)*a.sq(b) + eps; } // borders included XXX overflow
    inline bool has_inter_seg (vec a, vec b) { return has_inter_lin(a,b) && (contains(a) || contains(b) || a.dir(c,b)*b.dir(c,a) != -1); } // borders and tips included XXX overflow
    inline double arc_area (vec a, vec b) { return c.angle(a,b)*r*r/2; } // smallest arc, ccw positive
    inline double arc_len (vec a, vec b) { return c.angle(a,b)*r; } // smallest arc, ccw positive$
    pair<vec,vec> tan (vec v) { // XXX low precision
        if (contains(v) && !border(v)) throw 0;
        cood d2 = c.sq(v); double s = sqrt(d2 - r*r); s = (s==s)?s:0;
        double al = atan2(r,s); vec t = (~(c-v));
        return pair<vec,vec>(v + t.rotate(al)*s, v + t.rotate(-al)*s);
    }//$
    pair<vec,vec> border_inter (cir o) {
        if (!has_border_inter(o) || o.c == (*this).c) throw 0;
        double a = (sq(r) + o.c.sq(c) - sq(o.r))/(2*o.c.nr(c));
        vec v = (o.c - c)/o.c.nr(c); vec m = c + v * a;
        double h = sqrt(sq(r) - sq(a)); h = h!=h?0:h;
        return pair<vec,vec>(m + v.rot90()*h, m - v.rot90()*h);
    }//$
    pair<vec,vec> border_inter_lin (vec a, vec b) { // first is closest to a than second
        if (a.sq(b) <= eps) { if (border(a)) return pair<vec,vec>(a,a); throw 0; }
        if (a.dir(b,c) == -1) swap(a,b);
        if (!has_inter_lin(a,b)) throw 0;
        double d2 = c.dist2_lin(a,b); vec p = (b-a)/a.nr(b);
        double h = sqrt(r*r - d2); h = h!=h?0:h; 
        double y = sqrt(c.sq(a) - d2); y = y!=y?0:y;
        return pair<vec,vec>(a + p*(y-h), a + p*(y+h));
    }//$
    double triang_inter (vec a, vec b) { // ccw oriented, this with (c,a,b)
        if (c.sq(a) > c.sq(b)) return -triang_inter(b,a);
        if (contains(b)) return c.cross(a,b)/2;
        if (!has_inter_seg(a,b)) return arc_area(a,b);
        pair<vec,vec> itr = border_inter_lin(b,a); // order important
        if (contains(a)) return c.cross(a,itr.first)/2 + arc_area(itr.first,b);
        return arc_area(a,itr.second) + c.cross(itr.second,itr.first)/2 + arc_area(itr.first,b);
    }
}; //$

bool inter_seg (vec a, vec b, vec c, vec d) {
    if (a.in_seg(c, d) || b.in_seg(c, d) || c.in_seg(a, b) || d.in_seg(a, b)) return true;
    return (c.ccw(a, b) * d.ccw(a, b) == -1 && a.ccw(c, d) * b.ccw(c, d) == -1);
}

double dist2_seg (vec a, vec b, vec c, vec d){return inter_seg(a,b,c,d)?0.:min({ a.dist2_seg(c,d), b.dist2_seg(c,d), c.dist2_seg(a,b), d.dist2_seg(a,b) });}

cir min_spanning_circle (vec * v, int n) { // n
    srand(time(NULL)); random_shuffle(v, v+n); cir c(vec(), 0); int i,j,k;
    for (i = 0; i < n; i++) if (!c.contains(v[i]))
        for (c = cir(v[i],0), j = 0; j < i; j++) if (!c.contains(v[j]))
            for (c = cir((v[i] + v[j])/2,v[i].nr(v[j])/2), k = 0; k < j; k++) if (!c.contains(v[k]))
                    c = cir(v[i],v[j],v[k]);
    return c;
}//$

int convex_hull (vec * v, int n, int border_in) { // nlg | border_in (should border points stay?)
    swap(v[0], *min_element(v,v+n)); int s, i;
    sort(v+1, v+n, [&v] (vec a, vec b) { int o = b.ccw(v[0], a); return (o?o==1:v[0].sq(a)<v[0].sq(b)); });
    if (border_in) {
        for (s = n-1; s > 1 && v[s].ccw(v[s-1],v[0]) == 0; s--);
        reverse(v+s, v+n);
    }
    for (i = s = 0; i < n; i++) if (!s || !(v[s-1] == v[i])) {
        for (; s >= 2 && v[s-1].ccw(v[s-2],v[i]) >= border_in; s--);
        swap(v[s++],v[i]);
    }
    return s;
}//$

int monotone_chain (vec * v, int n, int border_in) { // nlg | border_in (should border points stay?)
    vector<vec> r; sort(v, v+n); n = unique(v, v+n) - v;
    for (int i = 0; i < n; r.pb(v[i++])) while (r.size() >= 2 && r[r.size()-2].ccw(r.back(),v[i]) <= -border_in) r.pop_back();
    r.pop_back(); unsigned int s = r.size();
    for (int i = n-1; i >= 0; r.pb(v[i--])) while (r.size() >= s+2 && r[r.size()-2].ccw(r.back(),v[i]) <= -border_in) r.pop_back();
    return copy(r.begin(), r.end() - (r.size() > 1), v) - v;
}//$

double polygon_inter (vec * p, int n, cir c) { // signed area
    return inner_product(p, p+n-1, p+1, c.triang_inter(p[n-1],p[0]), std::plus<double>(), [&c] (vec a, vec b) { return c.triang_inter(a,b); });
}//$

int polygon_pos (vec * p, int n, vec v) { // lg | p should be simple (-1 out, 0 border, 1 in)
    int in = -1; // it's a good idea to randomly rotate the points in the double case, numerically safer
    for (int i = 0; i < n; i++) {
        vec a = p[i], b = p[i?i-1:n-1]; if (a.x > b.x) swap(a,b);
        if (a.x + eps <= v.x && v.x < b.x + eps) { in *= v.ccw(a,b); }
        else if (v.in_seg(a,b)) { return 0; }
    }
    return in;
}//$

int polygon_pos_convex (vec * p, int n, vec v) { // lg(n) | (-1 out, 0 border, 1 in) TODO 
    if (v.sq(p[0]) <= eps) return 0;
    if (n <= 1) { return 0; } if (n == 2) { return v.in_seg(p[0],p[1])?0:-1; }
    if (v.ccw(p[0],p[1]) < 0 || v.ccw(p[0],p[n-1]) > 0) return -1;
    int di = lower_bound(p+1,p+n-1,v, [&p](vec a,vec v) { return v.ccw(p[0],a) > 0; }) - p;
    if (di == 1) return v.ccw(p[1],p[2]) >= 0?0:-1;
    return v.ccw(p[di-1],p[di]);
}//$

// v is the pointset, w is auxiliary with size at least equal to v's
cood closest_pair (vec * v, vec * w, int l, int r, bool sorted = 0) { // nlg | r is exclusive TODO (AC on cf, no test)
    if (l + 1 >= r) return inf;
    if (!sorted) sort(v+l,v+r,[](vec a, vec b){ return a.x < b.x; });
    int m = (l+r)/2; cood x = v[m].x;
    cood res = min(closest_pair(v,w,l,m,1),closest_pair(v,w,m,r,1));
    merge(v+l,v+m,v+m,v+r,w+l,[](vec a, vec b){ return a.y < b.y; });
    for (int i = l, s = l; i < r; i++) if (sq((v[i] = w[i]).x - x) < res) {
        for (int j = s-1; j >= l && sq(w[i].y - w[j].y) < res; j--)
            res = min(res, w[i].sq(w[j]));
        w[s++] = v[i];
    }
    return res;
}//$

double union_area (cir * v, int n) { // n^2lg | XXX joins equal circles TODO (AC on szkopul, no tests)
    struct I { vec v; int i; } c[2*(n+4)];
    srand(time(NULL)); cood res = 0; vector<bool> usd(n);
    cood lim = 1./0.; for (int i = 0; i < n; i++) lim = min(lim, v[i].c.y - v[i].r - 1);
    for (int i = 0, ss = 0; i < n; i++, ss = 0) {
        vec fp = v[i].c + vec(0,v[i].r).rotate(rand()); // rotation avoids corner on cnt initialization
        int cnt = 0, eq = 0; 
        for (int j = 0; j < n; j++) {
            cnt += (usd[j] = v[j].contains(fp));
            if (!v[i].has_border_inter(v[j])) continue;
            if (v[i].c == v[j].c) eq++;
            else {
                pair<vec,vec> r = v[i].border_inter(v[j]);
                c[ss++] = {r.first, j}; c[ss++] = {r.second, j};
            }
        }
        vec d = vec(v[i].r,0); for (int k = 0; k < 4; k++, d = d.rot90()) c[ss++] = {v[i].c + d, i};
        int md = partition(c,c+ss,[v,i,fp](I a){return a.v.ccw(v[i].c,fp) > 0;}) - c;
        sort(c,c+md,[v,i](I a,I b){return a.v.ccw(v[i].c,b.v) < 0;});
        sort(c+md,c+ss,[v,i](I a,I b){return a.v.ccw(v[i].c,b.v) < 0;});
        for (int j = 0; j < ss; j++) {
            if (c[j].i != i) { cnt -= usd[c[j].i]; usd[c[j].i] = !usd[c[j].i]; cnt += usd[c[j].i]; }
            vec a = c[j].v, b = c[(j+1)%ss].v;
            cood cir = abs(v[i].arc_area(a,b) - v[i].c.cross(a,b)/2), tra = abs((b.x-a.x)*(a.y+b.y-2*lim)/2);
            cood loc = (a.x<b.x)?cir-tra:tra+cir; res += (cnt==eq)?loc/eq:0;
        }
    }
    return res;
}//$

pii antipodal (vec * p, int n, vec v) { // lg(n) | extreme segments relative to direction v TODO
    // po: closest to dir, ne: furthest from dir
    bool sw = ((p[1]-p[0])*v < 0);
    if (sw) v = vec(0,0) - v; // lower_bound returns the first such that lambda is false
    int md = lower_bound(p+1, p+n, v, [p] (vec & a, vec v) { return (a-p[0])*v > eps; }) - p; // chain separation
    int po = lower_bound(p, p+md-1, v, [p,n] (vec & a, vec v) { return (p[(&a+1-p)%n]-a)*v > eps; }) - p; // positive
    int ne = (lower_bound(p+md, p+n, v, [p,n] (vec & a, vec v) { return (p[(&a+1-p)%n]-a)*v <= eps; }) - p)%n; // negative
    if (sw) swap(po,ne);
    return pii(po,ne);
}//$

int mink_sum (vec * a, int n, vec * b, int m, vec * r) { // (n+m) | a[0]+b[0] should belong to sum, doesn't create new border points TODO
    if (!n || !m) { return 0; } int i, j, s; r[0] = a[0] + b[0];
    for (i = 0, j = 0, s = 1; i < n || j < m; s++) {
        if (i >= n) j++;
        else if (j >= m) i++;
        else {
            int o = (a[(i+1)%n]+b[j%m]).ccw(r[s-1],a[i%n]+b[(j+1)%m]);
            j += (o >= 0); i += (o <= 0);
        }
        r[s] = a[i%n] + b[j%m];
    }
    return s-1;
}//$

int inter_convex (vec * p, int n, vec * q, int m, vec * r) { // (n+m) | XXX
    int a = 0, b = 0, aa = 0, ba = 0, inflag = 0, s = 0;
    while ((aa < n || ba < m) && aa < n+n && ba < m+m) {
        vec p1 = p[a], p2 = p[(a+1)%n], q1 = q[b], q2 = q[(b+1)%m];
        vec A = p2 - p1, B = q2 - q1;
        int cross = vec(0,0).ccw(A,B), ha = p1.ccw(p2,q2), hb = q1.ccw(q2,p2);
        if (cross == 0 && p2.ccw(p1,q1) == 0 && A*B < -eps) {
            if (q1.in_seg(p1,p2)) r[s++] = q1;
            if (q2.in_seg(p1,p2)) r[s++] = q2;
            if (p1.in_seg(q1,q2)) r[s++] = p1;
            if (p2.in_seg(q1,q2)) r[s++] = p2;
            if (s < 2) return s;
            inflag = 1; break;
        } else if (cross != 0 && inter_seg(p1,p2,q1,q2)) {
            if (inflag == 0) aa = ba = 0;
            r[s++] = lin(p1,p2).inter(lin(q1,q2));
            inflag = (hb > 0) ? 1 : -1;
        }
        if (cross == 0 && hb < 0 && ha < 0) return s;
        bool t = cross == 0 && hb == 0 && ha == 0;
        if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
            if (inflag == -1) r[s++] = q2;
            ba++; b++; b %= m;
        } else {
            if (inflag == 1) r[s++] = p2;
            aa++; a++; a %= n;
        }
    }
    if (inflag == 0) {
        if (polygon_pos_convex(q,m,p[0]) >= 0) { copy(p, p+n, r); return n; }
        if (polygon_pos_convex(p,n,q[0]) >= 0) { copy(q, q+m, r); return m; }
    }
    s = unique(r, r+s) - r;
    if (s > 1 && r[0] == r[s-1]) s--;
    return s;
}//$

bool isear (vec * p, int n, int i, int prev[], int next[]) { // aux to triangulate
    vec a = p[prev[i]], b = p[next[i]];
    if (b.ccw(a,p[i]) <= 0) return false;
    for (int j = 0; j < n; j++) {
        if (j == prev[i] || j == next[i]) continue;
        if (p[j].ccw(a,p[i]) >= 0 && p[j].ccw(p[i],b) >= 0 && p[j].ccw(b,a) >= 0) return false;
        int k = (j+1)%n;
        if (k == prev[i] || k == next[i]) continue;
        if (inter_seg(p[j],p[k],a,b)) return false;
    }
    return true;
}

int triangulate (vec * p, int n, bool ear[], int prev[], int next[], int tri[][3]) { // O(n^2) | n >= 3
    int s = 0, i = 0;
    for (int i = 0, prv = n-1; i < n; i++) { prev[i] = prv; prv = i; next[i] = (i+1)%n; ear[i] = isear(p,n,i,prev,next); }
    for (int lef = n; lef > 3; lef--, i = next[i]) {
        while (!ear[i]) i = next[i];
        tri[s][0] = prev[i]; tri[s][1] = i; tri[s][2] = next[i]; s++; // tri[i][0],i,tri[i][1] inserted
        int c_prev = prev[i], c_next = next[i];
        next[c_prev] = c_next; prev[c_next] = c_prev;
        ear[c_prev] = isear(p,n,c_prev,prev,next); ear[c_next] = isear(p,n,c_next,prev,next);
    }
    tri[s][0] = next[next[i]]; tri[s][1] = i; tri[s][2] = next[i]; s++; // tri[i][0],i,tri[i][1] inserted
    return s;
}