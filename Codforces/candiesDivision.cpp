//codeforces.com/contest/1283/problem/B

#include "bits/stdc++.h"
using namespace std;

#define p(x) cout << x << "\n"

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        int ans = (n/k)*k;

        n %= k;

        ans += min(n, k/2);

        p(ans);
    }
}
