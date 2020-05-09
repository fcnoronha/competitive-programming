#include "bits/stdc++.h"
using namespace std;

#define MAX 112345
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
int n, m, x, y, o[MAX], visited[MAX];
vector<int> adj[MAX];

ll dfs(int v, ll soma){
    visited[v] = 1;
    soma += o[v];

    for(int x : adj[v]){
        if(visited[x]) continue;

        soma += dfs(x, 0);
    }

    return soma;
}

int main() {
    fastio;
    ll soma;
    cin >> n >> m;
    // v[i] - quanto o cara i deve/recebe
    for(int i = 0; i < n; i++){
        cin >> o[i];
        visited[i] = 0;
    }
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]) soma = dfs(i, 0);        
        if(soma != 0){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
    return 0;
}