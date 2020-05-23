//codeforces.com/contest/1350/problem/C

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

    ll n;
    cin >> n;
    ll a[n];
    fr(i, n) cin >> a[i];
    ll pre[n], pos[n];
    pre[0] = a[0];
    pos[n-1] = a[n-1];
    for (int i = 1; i < n; i++) pre[i] = __gcd(pre[i-1], a[i]);
    for (int i = n-2; i >= 0; i--) pos[i] = __gcd(pos[i+1], a[i]);

    ll ans = pos[1];
    frr(i, n-1) {
        if (i == n-1) {
            ans = (ans*pre[n-2]) / __gcd(pre[n-2], ans);
            continue;
        }
        ans = (ans*__gcd(pre[i-1], pos[i+1]))/__gcd(__gcd(pre[i-1], pos[i+1]), ans);
    }
    p(ans);
}
