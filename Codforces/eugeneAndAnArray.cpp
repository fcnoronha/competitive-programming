//codeforces.com/contest/1333/problem/C

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

ll a[maxn], ac[maxn];

int main() {
    fastio;

    ll n;
    cin >> n;

    fr(i, n) {
        cin >> a[i];
        ac[i+1] = ac[i] + a[i];
    }

    map<ll, bool> mp;
    mp[0] = 1;
    int l = 0, r = 0;
    ll ans = 0ll;
    while (l < n) {
        while (r < n && !mp[ac[r+1]]) 
            mp[ac[++r]] = 1;
        ans += (r-l);
        mp[ac[l++]] = 0;
    }

    p(ans);
}
