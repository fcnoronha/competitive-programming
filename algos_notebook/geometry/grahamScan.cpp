// Graham-Scan to find convex hull in O(nlogn)
// Monotone chain version

typedef pair<int,int> point;
#define x first
#define y second
point p0;

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