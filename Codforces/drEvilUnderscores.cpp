//codeforces.com/contest/1285/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define p(x) cout << x << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef vector<int> vi;

int n;

int solve(vi v, int bit) {

    if (bit == -1 || !v.size()) return 0;

    vi one, zero;

    for (auto x: v) {

        if ( (x & (1 << bit)) == 0 ) zero.pb(x);
        else one.pb(x);
    }

    if (!one.size()) return solve(zero, bit-1);
    if (!zero.size()) return solve(one, bit-1);

    int ans = min(solve(one, bit-1), solve(zero, bit-1));
    ans |= (1 << bit);

    return ans;
}

int main(){
    fastio;
    
    cin >> n;

    int aux;
    vi v;
    fr(i, n) {
        cin >> aux;
        v.pb(aux);
    }

    p(solve(v, 31));
}
