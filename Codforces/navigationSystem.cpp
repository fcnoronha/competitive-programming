//codeforces.com/contest/1320/problem/B

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

#define maxn 200009

vi adj[maxn], adjinv[maxn];
int dist[maxn], seen[maxn], freq[maxn];

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    int u, v;
    fr(i, m) {
        cin >> u >> v;
        adj[v].pb(u);
        adjinv[u].pb(v);
    }

    int k;
    cin >> k;
    vi lst(k);
    fr(i, k) cin >> lst[i];

    int s = lst[0];
    int t = lst[k-1];
    
    queue<pii> q;
    q.push({t,0});
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        int u = x.f;
        int d = x.s;

        if (seen[u]) continue;
        seen[u] = 1;
        
        dist[u] = d;
        
        for (auto v: adj[u]) {
            if (seen[v]) continue;
            q.push({v, d+1});
        }
    }

    frr(u, n) 
        for (auto v: adjinv[u]) 
            if (dist[v] == dist[u]-1) 
                freq[u]++;

    int mn = 0, mx = 0;
    fr(i, k-1) {
        int u = lst[i];
        int v = lst[i+1];
        if (dist[v] >= dist[u]) mx++, mn++;
        else if (freq[u] > 1) mx++;
    }
    cout << mn << " " << mx << endl;
}
