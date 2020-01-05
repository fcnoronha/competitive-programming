//codeforces.com/contest/1284/problem/A

#include "bits/stdc++.h"
using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define p(x) cout << x << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fastio;

    int n, m;
    cin >> n >> m;

    string ss[n], ts[m];
    fr(i, n) cin >> ss[i];
    fr(i, m) cin >> ts[i];

    int q;
    cin >> q;

    while (q--) {

        int y;
        cin >> y;

        y--;

        string ans = ss[y%n] + ts[y%m];
        p(ans);
    }
    
}
