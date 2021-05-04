#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

int n, m;

bool solve(vi v, int x) {

    if (v[0]+x >= m) v[0] = 0;

    for (int i = 1; i < v.size(); i++) {

        if (v[i-1] > v[i]+x) return 0;

        if (v[i-1] >= v[i]) {
            v[i] = v[i-1];
            continue;
        }

        if (v[i]+x >= m && v[i-1] <= (v[i]+x)%m) 
            v[i] = v[i-1];
    }

    return 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    cin >> n >> m;

    vi v(n);
    fr(i, n) cin >> v[i];

    int l = 0, r = m;
    fr(abacaxi, 100) {
        int mid = (l+r)/2;
        if (solve(v, mid)) r = mid;
        else               l = mid+1;
    }

    p(l);
}
