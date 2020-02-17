//www.spoj.com/problems/MATCHING/

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

#define maxn 100009

vector<int> adj[maxn];
int l[maxn], r[maxn], seen[maxn];

void add_edge(int a, int b) {
    adj[a].push_back(b);
}

bool dfs(int node) {
    if (seen[node])
        return 0;
    seen[node] = 1;

    for (int vis: adj[node]) {
        if (r[vis] == -1) {
            l[node] = vis;
            r[vis] = node;
            return 1;
        }
    }

    for (int vis: adj[node]) {
        if (dfs(r[vis])) {
            l[node] = vis;
            r[vis] = node;
            return 1;
        }
    }
    return 0;
}

int kuhn(int n) {
    ms(l, -1);
    ms(r, -1);
    int ok = 1, cnt = 0;
    while (ok--) {
        ms(seen, 0);
        for (int i = 0; i < n; i++)
            if (l[i] == -1 && dfs(i)) {
                ok = 1;
                cnt++;
            }
    }
    return cnt;
}

int main(){
    fastio;

    int n, m, p;
    cin >> n >> m >> p;
    int clk = 0;
    int idc[n+1], idb[m+1];
    frr(i, n) idc[i] = clk++;
    frr(i, m) idb[i] = clk++;
    
    int c, b;
    fr(i, p) {
        cin >> c >> b;
        add_edge(idc[c], idb[b]);
    }

    cout << kuhn(n) << endl;
}
