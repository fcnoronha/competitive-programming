// TERNARY SEARCH
// O(log3 n), where n is the size of my set

// Interger version
int ts(int l, int r, int x){
i   
    while (l < r) {

        int m1 = l + (r-l) / 3;
        int m2 = r - (r-l) / 3;

        int f1 = f(m1); 
        int f2 = f(m2);

        // Change if wants minimum
        if (f1 < f2) l = m1+1;
        else         r = m2-1;
    }

    return f(l);
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