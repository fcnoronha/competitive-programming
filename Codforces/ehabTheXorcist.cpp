//codeforces.com/contest/1325/problem/D

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

    ll u, v;
    cin >> u >> v;

    if (u > v || u%2 != v%2) {
        p(-1);
        return 0;
    }

    if (u == v) {
        if (!u) p(0);
        else cout << "1\n" << u << endl;
        return 0;
    }

    ll x = (v-u)/2ll;
    if ((u&x) == 0ll) {
        p(2);
        cout << u+x << " " << x << endl;
        return 0;
    }

    p(3);
    cout << u << " " << x << " " << x << endl;
}
