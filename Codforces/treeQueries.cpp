//codeforces.com/contest/1328/problem/E

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

#define maxn 212345

int n, m;
vi adj[maxn], lst[maxn];
int cnt[maxn], seen[maxn];
set<int> st;

void dfs(int u, int prt) {

    for (auto v: adj[u]) if (v != prt) {
        for (auto qr: lst[v]) {
            if (seen[qr]) continue;
            cnt[qr]--;
            if (cnt[qr] == 0) seen[qr] = 1;
        }
    }
    for (auto v: adj[u]) if (v != prt) dfs(v, u);
    for (auto v: adj[u]) if (v != prt) {
        for (auto qr: lst[v]) {
            if (seen[qr]) continue;
            cnt[qr]++;
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;
    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    fr(i, m) {
        cin >> cnt[i];
        int u;
        fr(j, cnt[i]) {
            cin >> u;
            lst[u].pb(i);
        }
    }

    for (auto qr: lst[1]) {
        cnt[qr]--;
        if (cnt[qr] == 0) seen[qr] = 1;
    }

    dfs(1, 1);

    fr(i, m) {
        if (seen[i]) p("YES");
        else p("NO");
    }
}
