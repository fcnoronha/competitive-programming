//codeforces.com/contest/208/problem/E

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

#define maxn 112345

vi up[maxn], down[maxn], ans;
map<int, int> amt[maxn];
map<int, vi> qrs[maxn];
int lvl[maxn];

void dfs1(int u, int l) {
    lvl[u] = l;
    for (int v: down[u]) dfs1(v, l+1);
} 

void dfs2(int u) {

    for (auto v: down[u]) {
        dfs2(v);

        // stl
        if (amt[u].size() < amt[v].size()) swap(amt[u], amt[v]);
        for (auto x: amt[v]) amt[u][x.f] += x.s;
        amt[v].clear();

        if (qrs[u].size() < qrs[v].size()) swap(qrs[u], qrs[v]);
        for (auto &x: qrs[v]) {
            if (qrs[u][x.f].size() < x.s.size()) swap(qrs[u][x.f], x.s);
            for (auto xx: x.s) qrs[u][x.f].pb(xx);
        }
    }

    // precessing queries
    for (auto q: qrs[u][lvl[u]]) {
        int ql = -ans[q];
        ans[q] = amt[u][ql]-1;
    }
    qrs[u].erase(lvl[u]);
}

int main() {
    fastio;

    int n;
    cin >> n;

    fr(i, n) {
        int p;
        cin >> p;
        if (p == 0) continue;
        down[p].pb(i+1);
        up[i+1].pb(p);
    }

    frr(i, n) {
        if (up[i].size()) continue;
        dfs1(i, 1);
    }
    frr(i, n) amt[i][lvl[i]]++;
    
    int m;
    cin >> m;
    ans.resize(m);
    fr(i, m) {
        int v, p;
        cin >> v >> p;
        ans[i] = -lvl[v];
        qrs[v][lvl[v]-p].pb(i);
    }

    frr(i, n) {
        if (up[i].size()) continue;
        dfs2(i);
    }

    for (auto &x: ans) x = max(x, 0);
    pv(ans);
}
