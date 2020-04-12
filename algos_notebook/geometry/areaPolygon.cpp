// AREA OF SIMPLE POLYGON
// O(n)

// if the cordinates are interger we can return interger
double area(vector<pair<double, double>> p) {
    int n = p.size();
    double ans = 0.0;
    for (int i = 0; i < n; i++) 
        ans += (p[(i+1)%n].f + p[i].f) * (p[(i+1)%n].s - p[i].s);
    return abs(ans/2.0);
}