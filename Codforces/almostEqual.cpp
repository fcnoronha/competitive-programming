//codeforces.com/contest/1206/problem/C

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

int main(){
    fastio;

    int n;
    cin >> n;

    if (n%2 == 0) {
        p("NO");
        return 0;
    }

    pii v[n];
    v[0].f = 1;
    v[0].s = 2*n;

    int now[2] = {2*n, 2*n-2};
    frr(i, n-1) {

        int aux = now[i%2];
        v[i].s = aux - v[i-1].f;
        v[i].f = (2*n+1) - v[i].s;
    }

    int check = 1, x1 = ceil(n*(n+n+1)/2.0), x2 = n*(n+n+1)/2;
    vi ans;
    fr(i, n) ans.pb(v[i].f);
    for (int i = n-1; i >= 0; i--) ans.pb(v[i].s);

    p("YES");
    pv(ans);
}
