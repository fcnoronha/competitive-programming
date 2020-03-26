//codeforces.com/contest/1327/problem/E

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

#define maxn 212345
const ll mod = 998244353;

ll tenp[maxn];

int main() {
    fastio;

    ll n;
    cin >> n;

    tenp[0] = 1ll;
    frr(i, n) tenp[i] = (tenp[i-1]*10)%mod;

    frr(i, n) {
        if (i == n) {
            p(10);
            return 0;
        }

        ll a = (2*10*9*tenp[n-i-1])%mod;
        ll b = ((n-i-1)*10*9*9*tenp[n-i-2])%mod;
        a = (a+b)%mod;
        cout << a << " ";
    }
}
