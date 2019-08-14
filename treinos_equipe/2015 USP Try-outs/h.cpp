#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MAXN 11234
#define MAXM 4111111

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN], vis[MAXN];
int to[MAXM], nxt[MAXM];

ll cap[MAXM];
vi adj[MAXN];

bool cor[MAXN];

int n, m;

void init(){
    first[0] = -1;
    first[n + 1] = -1;
    ned = 0;
    frr(i, n){
        adj[i].clear();
        first[i] = -1;
        vis[i] = -1;
    }
}

void add(int u, int v, ll f) {
    to[ned] = v, cap[ned] = f;
    nxt[ned] = first[u];
    first[u] = ned++;

    to[ned] = u, cap[ned] = 0;
    nxt[ned] = first[v];
    first[v] = ned++;

}

int dfs(int u, ll f, int t){
    if(u == t) return f;
    for(int &e = work[u]; e != -1; e = nxt[e]){
        int v = to[e];
        if(dist[v] == dist[u] + 1 && cap[e] > 0){
            int df = dfs(v, min(f, cap[e]), t);
            if(df > 0){
                cap[e] -= df;
                cap[e^1] += df;
                return df;
            }
        }
    }
    return 0;
}

bool bfs(int s, int t){
    memset(&dist, -1, sizeof dist);
    dist[s] = 0;
    int st = 0, en = 0;
    q[en++] = s;
    while(en > st){
        int u = q[st++];
        for(int e = first[u]; e != -1; e = nxt[e]){
            int v = to[e];
            if(dist[v] < 0 && cap[e] > 0){
                dist[v] = dist[u] + 1;
                q[en++] = v;
            }
        }
    }
    return dist[t] >= 0;
}

int dinic(int s, int t){
    int result = 0, f;
    while(bfs(s, t)){
        memcpy(work, first, sizeof work);
        while(f = dfs(s, INF, t)) result += f;
    }

    return result;
}

void bipart(int v, bool color){
    vis[v] = 0;
    cor[v] = color;
    if(color){
        add(0, v, 1);
    }
    else add(v, n+1, 1);

    for(auto x: adj[v]){
        if(vis[x] != -1) continue;
        bipart(x, !color);
    }
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        init();
        fr(i, m){
            int a, b; scanf("%d%d", &a, &b);
            if(a == b) continue;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        bipart(1, true);

        frr(i, n){
            if(!cor[i]) continue;
            for(auto x: adj[i]){
                add(i, x, 1);
            }
        }

        ll ans = dinic(0, n+1);
        //dbg(ans);
        printf("%lld\n", ans + (n - 2*ans));
    }
}
