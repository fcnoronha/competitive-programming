// Algorithms to check if point is inside polgon

typedef long long int ll;
#define f first
#define s second

typedef pair<ll, ll> pt;
int sgn(ll val){
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

ll cross(pt a, pt b) {
    return a.f*b.s - a.s*b.f;
}

ll cross(pt a, pt b, pt c) { 
    pt x = {b.f-a.f, b.s-a.s};
    pt y = {c.f-a.f, c.s-a.s};
    return cross(x, y);
}

ll dot2(pt a) {
    return a.f*a.f + a.s+a.s;
}

bool insideT(pt a, pt b, pt c, pt p){
    ll s1 = abs(cross(a, b, c));
    ll s2 = abs(cross(p, a, b)) + abs(cross(p, b, c)) + abs(cross(p, c, a));
    return s1 == s2;
}

vector<pt> prepare(vector<pt> &pol) {
    
    int n = pol.size(), pos = 0;
    for (int i = 1; i < n; i++)
        if (pol[i] < pol[pos])
            pos = i;
    
    rotate(pol.begin(), pol.begin() + pos, pol.end());

    n--;
    vector<pt> seq(n);
    for(int i = 0; i < n; i++)
        seq[i] = {pol[i+1].f-pol[0].f, pol[i+1].s-pol[0].s};
    return seq;
}

bool isInside(pt p, vector<pt> &pol){

    pol = prepare(pol);
    int n = pol.size();
    if (cross(pol[0], p) != 0 && sgn(cross(pol[0], p)) != sgn(cross(pol[0], pol[n])))
        return 0;
    if (cross(pol[n], p) != 0 && sgn(cross(pol[n], p)) != sgn(cross(pol[n], pol[0])))
        return false;

    if (cross(pol[0], p) == 0) return dot2(pol[0]) >= dot2(p);

    int l = 0, r = n;
    while (r-l > 1){
        int mid = (l+r)/2;
        int pos = mid;
        if (cross(pol[pos], p) >= 0) l = mid;
        else r = mid;
    }
    int pos = l;
    return insideT(pol[pos], pol[pos+1], {0,0}, p);
}
