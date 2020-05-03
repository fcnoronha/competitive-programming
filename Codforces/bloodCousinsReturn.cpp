//codeforces.com/contest/246/problem/E

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << "\n"

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

#define marx 112345

vi up[marx], down[marx], ans, qrs[marx];
map<int, set<string>> amt[marx];
int lvl[marx];
string name[marx];

void dfs1(int u, int l) {
    lvl[u] = l;
    for (int v: down[u]) dfs1(v, l+1);
} 

void dfs2(int u) {

    for (auto v: down[u]) {
        dfs2(v);

        // stl
        if (amt[u].size() < amt[v].size()) swap(amt[u], amt[v]);
        for (auto &x: amt[v]) {
            if (amt[u][x.f].size() < x.s.size()) swap(x.s, amt[u][x.f]);
            for (auto s: x.s) amt[u][x.f].insert(s);
        }
        amt[v].clear();
    }

    // precessing queries
    for (auto q: qrs[u]) {
        int ql = ans[q];
        ans[q] = amt[u][ql].size();
    }
}

int main() {
    fastio;

    int n;
    cin >> n;

    frr(i, n) {
        string s;
        int p;
        cin >> s >> p;
        name[i] = s;
        if (p == 0) continue;
        down[p].pb(i);
        up[i].pb(p);
    }

    frr(i, n) {
        if (up[i].size()) continue;
        dfs1(i, 1);
    }
    frr(i, n) amt[i][lvl[i]].insert(name[i]);
    
    int m;
    cin >> m;
    ans.resize(m);
    fr(i, m) {
        int v, k;
        cin >> v >> k;
        ans[i] = lvl[v]+k;
        qrs[v].pb(i);
    }

    frr(i, n) {
        if (up[i].size()) continue;
        dfs2(i);
    }

    for (auto &x: ans) x = max(x, 0);
    pv(ans);
}
