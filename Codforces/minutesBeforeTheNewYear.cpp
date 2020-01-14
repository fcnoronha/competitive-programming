//codeforces.com/contest/1283/problem/A

#include "bits/stdc++.h"
using namespace std;

#define p(x) cout << x << "\n"

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int h, m;
        cin >> h >> m;

        if (!h && !m) {
            p("0");
            continue;
        }

        int ans = 60-m;
        ans += (23-h)*60;

        p(ans);
    }
}
