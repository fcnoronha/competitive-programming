//codeforces.com/contest/1370/problem/C

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << '\n'
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    fastio;

    int tt;
    cin >> tt;
    while (tt--) {
        ll n, ok = 1;
        cin >> n;

        if (n == 1) ok = 0;
        if (__builtin_popcount(n) == 1 && n > 2) ok = 0; 

        bool is_p = 0;
        if (n%2 == 0 && n > 4) {
            int x = n/2;
            is_p = 1;
            for (int d = 2; d*d <= x; d++) {
                if (x%d == 0) {
                    is_p = 0;
                    break;
                }
            }
        }
        if (is_p) ok = 0;

        if (ok) p("Ashishgup");
        else    p("FastestFinger");
    } 
}
