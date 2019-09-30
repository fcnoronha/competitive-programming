//onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1140
// 10199 - Tourist Guide

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

vi adj[109];
bool visited[109];

int ans, q, cnt, r, n, timer;
int tin[109], low[109];

set<string> anss;
string ct[109];

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to])
            low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1)
                anss.insert(ct[v]);
            children++;
        }
    }
    if(p == -1 && children > 1)
        anss.insert(ct[v]);
}

void find_cutpoints() {
    timer = 0;
    ms(tin, -1);
    ms(low, -1);
    ms(visited, 0);
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs(i);
}

int main(){
    fastio

    q = 1;
    while (cin >> n && n) {

        if (q > 1) cout << "\n";

        fr(i, n) adj[i].clear();
        anss.clear();

        map<string, int> mp;
        string s, t;

        fr(i, n) {
            cin >> s;
            ct[i] = s;
            mp[s] = i;
        }

        r;
        cin >> r;
        while (r--) {
            cin >> s >> t;
            int u = mp[s];
            int v = mp[t];
            adj[u].pb(v);
            adj[v].pb(u);
        }

        ans = 0;
        find_cutpoints();

        cout << "City map #" << q++ << ": " << anss.size() << " camera(s) found\n";
        for (auto x : anss)
            cout << x << "\n";
    }
}
