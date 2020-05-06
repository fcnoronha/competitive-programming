//www.codechef.com/problems/PRIMEDST

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

#define maxn 51234

// CENTROID DECOMP
vi adj[maxn];
int seen[maxn], sz[maxn];

void get_sz(int u, int p) {
    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue;
        get_sz(v, u);
        sz[u] += sz[v];
    } 
}

int dfs_centroid(int u, int p, int n) {
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue;
        if (sz[v] > n/2) return dfs_centroid(v, u, n);
    }
    return u;
}

int find_centroid(int r) {
    get_sz(r, r);
    int n = sz[r];
    return dfs_centroid(r, r, n);
}

// PRIMES

vi isPrime(maxn, true);
vi pr;
vi SPF(maxn);

void seive(int n) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            pr.push_back(i);
            SPF[i] = i;
        }
        for (int j = 0; j < pr.size() && i*pr[j] < n && pr[j] <= SPF[i]; j++) {
            isPrime[i*pr[j]] = false;
            SPF[i*pr[j]] = pr[j] ;
        }
    }
}

// PROBLEM ITSELF

ll  ans;
ll amt[20][maxn];

void dist_dfs(int u, int p, ll dis, int val, int lvl) {
    amt[lvl][dis] += val;
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue;
        dist_dfs(v, u, dis+1, val, lvl);
    }
}

ll calc_dfs(int u, int p, ll dis, int lvl) {
    ll ret = 0ll;
    for (auto prime: pr) {
        ll delta = prime-dis;
        if (delta < 0) continue;
        if (amt[lvl][delta] == 0) break;  
        ret += amt[lvl][delta];
        if (prime == dis) ret += amt[lvl][delta]; 
    }
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue;
        ret += calc_dfs(v, u, dis+1, lvl);
    }
    return ret;
}

void decomposition(int u, int lvl) {
    int c = find_centroid(u);
    seen[c] = 1;

    dist_dfs(c, c, 0, 1, lvl);
    for (auto v: adj[c]) {
        if (seen[v]) continue;
        dist_dfs(v, c, 1, -1, lvl);
        ans += calc_dfs(v, c, 1, lvl);
        dist_dfs(v, c, 1, 1, lvl);
    }

    for (auto v: adj[c]) {
        if (seen[v]) continue;
        decomposition(v, lvl+1); 
    }
    for (int i = 0; amt[lvl][i]; i++) amt[lvl][i] = 0;
}


int main() {
    fastio;

    ll n;
    cin >> n;

    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    seive(n+10);
    decomposition(1, 0);

    ans /= 2;
    ll comb = (n*(n-1ll))/2ll;
    cout << setprecision(7) << fixed << double(ans)/double(comb) << endl;
}
