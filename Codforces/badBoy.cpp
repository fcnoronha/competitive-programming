//codeforces.com/contest/1537/problem/B

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

ll dist(pii a, pii b) {
    return abs(a.f-b.f) + abs(a.s-b.s);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;


    int t; cin >> t;
    while (t--) {

        ll n, m; cin >> n >> m;
        ll i, j; cin >> i >> j;

        vector<pll> pos({{1, 1}, {1, m}, {n, 1}, {n, m}});
        pll x1, x2;
        ll ans = -1;

        for (auto a: pos) for (auto b: pos) {
            ll x = dist({i,j}, a) + dist({i,j}, b) + dist(a, b);
            if (x > ans) {
                x1 = a;
                x2 = b;
                ans = x;
            }
        }

        cout << x1.f << " " << x1.s << " " << x2.f << " " << x2.s << endl; 
    }
}
