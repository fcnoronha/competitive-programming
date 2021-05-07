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

#define maxn 112345

ll a[maxn], op_d[maxn], ac_q[maxn], ac_a[maxn];
pll lim[maxn];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    
    int n, m, k;
    cin >> n >> m >> k;

    frr(i, n) cin >> a[i];
    frr(i, m) cin >> lim[i].f >> lim[i].s >> op_d[i];
    frr(i, k) {
        int x, y;
        cin >> x >> y;
        ac_q[x]++;
        ac_q[y+1]--;
    }

    ll ac = 0;
    frr(i, m) {
        ac += ac_q[i];
        ll x = ac*op_d[i];
        ac_a[lim[i].f] += x;
        ac_a[lim[i].s+1] -= x;
    }

    ac = 0;
    frr(i, n) {
        ac += ac_a[i];
        a[i] += ac;
    }

    frr(i, n) cout << a[i] << " \n"[i==n];
}
