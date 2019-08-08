//www.e-olymp.com/en/problems/2923

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

vi adj[1000009];
int col[1000009];
int ans[1000009];

void dfs(int v, unordered_map<int, int> &mp) {

    for (auto u : adj[v]) {
        unordered_map<int, int> aux;
        dfs(u, aux);

        if (aux.size() > mp.size())
            swap(aux, mp);

        for (auto x : aux)
            mp[x.f]++;
    }

    mp[col[v]]++;
    ans[v] = mp.size();
}

int main(){
    fastio

    int n;
    cin >> n;

    int c, p;
    frr(i, n) {
        cin >> p >> c;

        adj[p].pb(i);
        col[i] = c;
    }

    unordered_map<int, int> mp;
    dfs(0, mp);

    frr(i, n) cout << ans[i] << " \n"[i == n];
}
