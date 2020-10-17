//codeforces.com/contest/1422/problem/B

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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;
    while (t--) {

        ll n, m;
        cin >> n >> m;

        ll v[n][m];
        fr(i, n) fr(j, m) cin >> v[i][j];

        ll ans = 0ll;
        fr(i, (n+1)/2) {
            fr(j, (m+1)/2) {
                vl aux;

                set<pll> porra;
                porra.insert({i, j});
                porra.insert({n-i-1, j});
                porra.insert({i, m-j-1});
                porra.insert({n-i-1, m-j-1});

                for (auto aaaaaa: porra) aux.pb(v[aaaaaa.f][aaaaaa.s]);

                ll a1 = LINF, l = 0ll, r = INF;
                fr(auhhss, 100) {
                    ll m1 = l + (r-l)/3ll;
                    ll m2 = r - (r-l)/3ll;

                    ll f1 = 0ll;
                    for (auto x: aux) f1 += abs(x-m1);
                    
                    ll f2 = 0ll;
                    for (auto x: aux) f2 += abs(x-m2);

                    a1 = min({a1, f1, f2});
                    if (f1 > f2) l = m1;
                    else		 r = m2;
                }
                ans += a1;
            }
        }

        p(ans);
    }
}
