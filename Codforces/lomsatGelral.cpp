//codeforces.com/contest/600/problem/E

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

ll c[100009], ans[100009];
vi adj[100009];

map<ll, ll> dfs(int v, int p, pll &aux) {

    map<ll, ll> ret;
    ret[c[v]]++;
    aux = {c[v], 1ll};

    for (auto u : adj[v]) {

        if (p == u) continue;

        pll auxx;
        auto m = dfs(u, v, auxx);

        if (m.size() > ret.size()) {
            swap(ret, m);
            swap(aux, auxx);
        }

        for (auto x : m) {

            ll col = x.f;
            ll &amt = ret[x.f];
            amt += x.s;

            if (amt < aux.s) continue;

            if (amt > aux.s)
                aux = {col, amt};
            else
                aux = {aux.f+x.f, amt};
        }
    }

    ans[v] = aux.f;
    return ret;
}

int main(){
    fastio

    int n;
    cin >> n;

    frr(i, n) cin >> c[i];
    int x, y;

    fr(i, n-1) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    pll aux;
    dfs(1, 0, aux);
    frr(i, n) cout << ans[i] << " \n"[i == n];
}
