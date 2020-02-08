
// Gaussian elimination - solve linear systems
// O(n³)

const double EPS = 10e-9;

// Vector A has n lines (n systems) and m columns (variable).
// Return the number os solutions and solution is stored in ans
int gauss (vector< vector<double> > a, vector<double> &ans) {
    int n = a.size();
    int m = a[0].size()-1;

    vector<int> where(m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if (abs(a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

// Code for max xor subset
void maxXOR (vl a, ll &ans) {
    ll n = a.size();
    ll m = 62; // last ll bit
    for (ll col=m, row=0; col >= 0 && row<n; col--) {
        ll sel = -1;
        for (ll i=row; i<n; ++i)
            if (a[i] & (1LL<<col)) {
                sel = i;
                break;
            }
        if (sel == -1) continue;
        swap(a[sel], a[row]);
        for (ll i=row+1; i<n; ++i)
            if (a[i] & (1LL<<col))
                a[i] ^= a[row];
        ++row;
    }
    fr(i, n) ans = max(ans, ans^a[i]);
}
