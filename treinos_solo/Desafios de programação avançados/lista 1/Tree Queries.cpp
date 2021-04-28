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

#define maxn 212345

vi adj[maxn], is_part[maxn];
int cnt[maxn];
bool deu[maxn];

void dfs(int u, int prt) {

    for (auto v: adj[u]) {
        if (v == prt) continue;
        for (auto y: is_part[v]) {
            cnt[y]--;
            if (cnt[y] == 0) deu[y] = 1;
        }
    }

    for (auto v: adj[u]) {
        if (v == prt) continue;
        dfs(v, u);
    }

    for (auto v: adj[u]) {
        if (v == prt) continue;
        for (auto y: is_part[v]) {
            cnt[y]++;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, m;
    cin >> n >> m;

    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    fr(i, m) {
        cin >> cnt[i];
        fr(j, cnt[i]) {
            int x; cin >> x;
            is_part[x].pb(i);
        }
    }

    for (auto x: is_part[1]) {
        cnt[x]--;
        if (cnt[x] == 0) deu[x] = 1;
    }

    dfs(1, 1);

    fr(i, m) {
        if (deu[i]) p("YES");
        else     p("NO");
    }
}
