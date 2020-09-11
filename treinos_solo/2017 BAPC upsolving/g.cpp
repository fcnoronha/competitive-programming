#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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

bool check(int msk, vi &v) {
    int aux = 0;
    fr(i, v.size()) 
        if ((1<<i) & msk) 
            aux += v[i];
    return (aux == 0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int m, n;
    cin >> m >> n;

    int blc[m];
    ms(blc, 0);
    while (n--) {
        int a, b, p;
        cin >> a >> b >> p;
        blc[a] -= p;
        blc[b] += p;
    }

    vi v;
    fr(i, m) if (blc[i]) v.pb(blc[i]);

    n = v.size();
    int ans = n-1;
    vi memo(1<<(n+1), 0);

    fr(msk, (1<<n)) {
        fr(i, n) 
            if ((1<<i)&msk) 
                memo[msk] = max(memo[msk], memo[msk-(1<<i)]);
        memo[msk] += check(msk, v);
        ans = min(ans, n-memo[msk]);
    }

    p(ans+1);
}
