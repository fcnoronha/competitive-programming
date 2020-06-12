//codeforces.com/problemset/problem/908/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    fastio;

    int n;
    double r;
    cin >> n >> r;
    double x[n], y[n];
    fr(i, n) {
        cin >> x[i];
        y[i] = r;

        for (int j = i-1; j >= 0; j--) {
            double dx = abs(x[i]-x[j]); 
            if (dx > 2.0*r) continue;
            double dy = sqrt(4.0*r*r - dx*dx);
            y[i] = max(y[i], y[j]+dy);
        }
    }

    cout << setprecision(9) << fixed;
    fr(i, n) cout << y[i] << " \n"[i == n-1];
}
