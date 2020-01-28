#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int memo[109][10009], a[109];
int n, act;

int pd(int i, int j) {

    if (i == n) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    int pd1 = max(j+a[i], pd(i+1, j+a[i]));
    int pd2 = max(abs(j-a[i]), pd(i+1, abs(j-a[i])));

    memo[i][j] = min(pd1, pd2);
    return memo[i][j];
}

int main(){
	fastio

    int t;
    cin >> t;

    while (t--) {

        cin >> n;

        fr(i, n) {
            cin >> a[i];
            ms(memo[i], -1);
        }

        p(pd(0, 0));
    }
}
