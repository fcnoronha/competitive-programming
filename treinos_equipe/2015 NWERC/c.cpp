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

#define maxn 31234

pll well[maxn], pipe[maxn];
int w, p, ori[maxn];  

/////////////////////////////////////////////////
// PUTARIA DE PONTO

map<pair<pll, pll>, vi> inter;
pll reg(pll x) {
    ll a = x.f, b = x.s;
    if (a == 0) return {0ll, 0ll};
    if (b == 0) return {INF, INF};
    if (b < 0) a = -a, b = -b;
    ll g = __gcd(abs(a), abs(b));
    return {a/g, b/g};
}

int is_left(pll a, pll b, pll c) {
    ll det = (b.f-a.f)*(c.s-a.s) - (c.f-a.f)*(b.s-a.s);
    if (det > 0) return 1;  // c is to the left
    if (det < 0) return -1; // c is to the right
    return 0;               // c is collinear
}

bool is_inter(pll a, pll b, pll c, pll d) {
    if (b == d) return 1;
    int l1 = is_left(a, b, c);
    int l2 = is_left(a, b, d);
    int l3 = is_left(c, d, a);
    int l4 = is_left(c, d, b);
    return (l1 != l2) && (l3 != l4);
}

// https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
// linhas a-b c-d
pair<pll, pll> get_inter(pll a, pll b, pll c, pll d) {
    ll x1 = a.f, y1 = a.s;
    ll x2 = b.f, y2 = b.s;
    ll x3 = c.f, y3 = c.s;
    ll x4 = d.f, y4 = d.s;

    ll xn = ((x1*y2) - (y1*x2))*(x3-x4) - (x1-x2)*((x3*y4) - (y3*x4));
    ll xd = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4); 
    pll x = reg({xn, xd});

    ll yn = ((x1*y2) - (y1*x2))*(y3-y4) - (y1-y2)*((x3*y4) - (y3*x4));
    ll yd = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
    pll y = reg({yn, yd});

    return {x, y};
}


/////////////////////////////////////////////////
// PUTARIA DE 2SAT

int low[maxn], pre[maxn], id[maxn];
int clk = 0, cnt = 0, numSCC = 0; // cnt == 2*(#elements) 
bool eval[maxn];

vector<int> adj[maxn];
stack<int> nodes;

void dfs(int v){
    nodes.push(v);
    pre[v] = low[v] = clk++;
    for (auto x: adj[v]) {
        if (pre[x] == -1) dfs(x);
        low[v] = min(low[v], low[x]);
    }
    if (low[v] == pre[v]) {
        while (1) {
            int j = nodes.top();
            nodes.pop();
            id[j] = numSCC;
            low[j] = INF;
            if (j == v) break;
        }
        numSCC++;
    }
}

int neg(int i) {
    if (i <= cnt/2) return i + cnt/2;
    return i - cnt/2; 
}

void add_imp(int i, int j) {
    adj[i].pb(j);
}

void add_or(int i, int j) {
    add_imp(neg(i), j);
    add_imp(neg(j), i);
}

void add_xor(int i, int j) {
    add_or(i, j);
    add_or(neg(i), neg(j));
}

void force_var(int i) {
    add_imp(neg(i), i);
}

bool sat() {
    for (int i = 1; i <= cnt; i++)
        if (pre[i] == -1) dfs(i);
    for (int i = 1; i <= cnt/2; i++) {
        if (id[i] == id[neg(i)]) return 0;
        eval[i] = (id[i] < id[neg(i)]);
        eval[neg(i)] = !eval[i];
    }
    return 1;
}

////////////////////////////////////////////////////////Q

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    cin >> w >> p;

    fr(i, w) cin >> well[i].f >> well[i].s;
    fr(i, p) cin >> ori[i] >> pipe[i].f >> pipe[i].s, ori[i]--;

    fr(i, p) {
        fr(j, p) {
            int oi = ori[i], oj = ori[j];
            if (j <= i) continue;
            if (oi == oj) continue;
            if (!is_inter(well[oi], pipe[i], well[oj], pipe[j])) continue;

            auto it = get_inter(well[oi], pipe[i], well[oj], pipe[j]);
            inter[it].pb(i);
            inter[it].pb(j);
        }
    }

    cnt = p+p+p;
    ms(pre, -1);
    for (auto x: inter) {
        assert(x.s.size() == 2);
        int i = x.s[0], j = x.s[1];
        add_xor(i+1, j+1);
    }

    if (sat()) p("possible");
    else       p("impossible");
}
