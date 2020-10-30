#include "bits/stdc++.h"
#include<chrono>
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

ll is_left(pll a, pll b, pll c) {
    ll det = (b.f-a.f)*(c.s-a.s) - (c.f-a.f)*(b.s-a.s);
    if (det > 0) return 1;  // c is to the left
    if (det < 0) return -1; // c is to the right
    return 0;               // c is collinear
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    ll n, pct;
    cin >> n >> pct;

    pll p[n];
    fr(i, n) cin >> p[i].f >> p[i].s;

    map<pair<int, int>, bool> mp;
    auto start = chrono::steady_clock::now();
    while (chrono::steady_clock::now() - start < std::chrono::milliseconds(3900)) {
        int i = uniform_int_distribution<int>(0, n-1)(rng);
        int j = uniform_int_distribution<int>(0, n-1)(rng);
        if (i == j) i = (i+1)%n;

        if (mp[{i,j}]) continue;
        mp[{i,j}] = 1;

        int cnt = 2;
        fr(k, n) {
            if (k == i || k == j) continue;
            cnt += is_left(p[i], p[j], p[k]) == 0;
        }

        if (cnt >= ((n*pct + 99ll) / 100ll)) {
            p("possible");
            return 0;
        }
    }

    p("impossible");
}
