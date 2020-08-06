#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, 
        tree_order_statistics_node_update> ordered_set;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 5e5 + 1000;
int clk = -1;

vii adj[N];
int ans[N], c[N];
ll dist[N];

ordered_set dfs(int v, int p){
    ordered_set cur, plc;
    for(auto pp: adj[v]){
        if(pp.ff == p) continue;
        plc = dfs(pp.ff, v);
        if(plc.size() > cur.size()){
            for(auto val: cur)
                plc.insert(val);
            cur = plc;
        }
        else{
            for(auto val: plc)
                cur.insert(val);
        }   
    }
    clk--;
    ans[v] = cur.order_of_key(mp(dist[v], -clk));
    cur.insert(mp(dist[v] - c[v], clk));
    return cur;
}

void build(int v, int p){
    for(auto pp: adj[v]){
        if(pp.ff == p) continue;
        else dist[pp.ff] = dist[v] +(ll)pp.ss, build(pp.ff, v);
    }
}

int main(){
    freopen("car.in", "r", stdin);
    rvr(t);
    while(t--){
        clk = -1;
        rvr(n);
        frr(i, n) scanf("%d", &c[i]);
        frr(i, n) adj[i].clear();
        fr(i, n-1){
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            adj[a].pb(mp(b, c));
            adj[b].pb(mp(a, c));
        }
        dist[1] = 0;
        build(1, 1);
        dfs(1, 1);
        frr(i, n) printf("%d%c", ans[i], " \n"[i==n]);
    }
}
