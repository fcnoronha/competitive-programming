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

vi adj[500];
int cnt;
vector<bool> vis;

void dfs(int v) {

    if (vis[v]) return;
    vis[v] = 1;

    for (auto u : adj[v])
        dfs(u);
}

bool cmp(string oi) {

    reverse(all(oi));
    string prg = "MARGORP:";

    if (oi.size() < 9) return false;
    fr(i, 8)
        if (oi[i] != prg[i])
            return false;

    return true;
}

int main(){
    fastio

    int n;
    cin >> n;

    map<string, int> mp;
    set<int> programs; // executable methods

    fr(i, n) {

        string child;
        int k;
        cin >> child;
        cin >> k;

        if (mp.find(child) == mp.end())
            mp[child] = cnt++;

        if (cmp(child))
            programs.insert(mp[child]);

        fr(i, k) {

            string parent;
            cin >> parent;

            if (mp.find(parent) == mp.end())
                mp[parent] = cnt++;

            if (cmp(parent))
                programs.insert(mp[parent]);

            adj[mp[parent]].pb(mp[child]);
        }
    }

    vis.resize(cnt);
    fr(i, cnt) vis[i] = 0;

    for (auto x : programs)
        dfs(x);

    cnt = 0;
    for (auto x : vis)
        cnt += !x;

    p(cnt);
}
