// TERNARY SEARCH
// O(log3 n), where n is the size of my set

// Interger version
int a[MAXN]; // Array with my values
int ts(int l, int r, int x){
    // Returns possition of X in array A
    if (l > r) return -1; // Can't find
    int m1 = l + (r-l) / 3;
    int m2 = m1 + (r-l) / 3;
    if (a[m1] == x) return m1;
    if (a[m2] == x) return m2;
    if (x < a[m1]) return ts(l, m1-1, x);
    if (x > a[m2]) return ts(m2+1, r, x);
    return ts(m1+1, m2-1, x);
}

// Double inplementation, used for functions
// To use with with interger just change the types your dumb ass
double ts(double l, double r) {
    // Return maximum value of f(x) in [l, r]
    double eps = 1e-9;
    while (r - l > eps) {
        double m1 = l + (r-l) / 3;
        double m2 = r - (r-l) / 3;
        double f1 = f(m1);   
        double f2 = f(m2);     
        // Change if wants minimum
        if (f1 < f2) l = m1;
        else		 r = m2;
    }
    return f(l);   
}