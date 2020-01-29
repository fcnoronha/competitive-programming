#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define mp make_pair

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
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500*500 + 2;
const int N = MAXN;
const int LMAXN = 22;

struct edge{
    int u;
    int v;
    ll w;
};

bool mycomp(edge a, edge b){
    return a.w > b.w;
}

vector<edge> edges;
vector<int> adj[600];

vector<edge> edj[MAXN]; 

pii points[600];

map<pii, int> id;

int vis[MAXN];

int idd = 0;

ll ans[MAXN][LMAXN + 1];

int memo[MAXN][LMAXN + 1];
int hgt[MAXN];

int par[N], depth[N];


int find(int x){
	return (par[x] == x)?x:(par[x] = find(par[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(depth[x] > depth[y]) swap(x, y);

	par[x] = y;
	if(depth[x] == depth[y]) depth[y]++;

}


void dfslca(int v){
	
	for(auto e : edj[v]){

        int filho = e.u + e.v - v; 
	
		if(hgt[filho] != -1)	continue;
	
		memo[filho][0] = v;		//seta o pai do cara
		hgt[filho] = hgt[v] + 1;
        ans[filho][0] = e.w;
		
		for(int i=1;i<LMAXN;i++){
            if(memo[filho][i-1] != -1){
                ans[filho][i] = min(ans[filho][i-1], ans[memo[filho][i-1]][i-1]);
                memo[filho][i] = memo[memo[filho][i-1]][i-1];
            }
        }	
		
        dfslca(filho);
	}

}

ll lca(int a, int b){

	if(hgt[a]<hgt[b])	swap(a,b);		//quero que a seja o cara mais profundo na arvore

    ll plc = LINF;

	for(int i=LMAXN-1; i>=0; i-- ){						//bota a e b na mesma altura
		if(memo[a][i] != -1 && hgt[ memo[a][i] ] >= hgt[b])	plc = min(plc, ans[a][i]), a=memo[a][i];	//vou subir o a ate ele ficar no mesmo nivel do b
	}

	if(a==b)	return plc;

	for(int i=LMAXN-1; i>=0; i--){	//vai pulando ate ficarem ambos a e b um nivel antes do LCA
		if(memo[a][i] == -1 || memo[a][i] == memo[b][i]) continue;
        plc = min(plc, ans[a][i]);
        plc = min(plc, ans[b][i]);
		a=memo[a][i];
		b=memo[b][i];
	}

	return min(min(ans[b][0], ans[a][0]), plc);	//sobe um nivel e retorna o lca

}

ll dcalc(int a, int b){
    return (points[a].first - points[b].first)*(points[a].first - points[b].first) + (points[a].second - points[b].second)*(points[a].second - points[b].second);
}

void build(pii cur){
    vis[id[cur]] = true;
    for(auto v: adj[cur.first]){
        for(auto u: adj[cur.second]){
            pii plc = mp(v, u);
            if(id[plc] == 0) id[plc] = ++idd;
            edges.pb((edge){id[cur], id[plc], min(dcalc(cur.first, cur.second), dcalc(v, u))});
            if(vis[id[plc]]) continue;
            build(plc);
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    frr(i, n){
        int a, b; scanf("%d%d", &a, &b);
        points[i] = make_pair(a, b);
    }
    int m; scanf("%d", &m);
    fr(i, m){
        int a, b; scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int l; scanf("%d", &l);
    vector<pii> st;
    fr(i, l){
        int a, b; scanf("%d%d", &a, &b);
        pii plc = mp(a, b);
        st.pb(plc);
        if(id[plc] == 0) id[plc] = ++idd, build(plc);
    }
    frr(i, idd){
        par[i] = i;
    }
    sort(all(edges), mycomp);
    for(auto e: edges){
        if(find(e.u) != find(e.v)){
            edj[e.u].pb(e);
            edj[e.v].pb(e);
            join(e.u, e.v);
        }
    }
    ms(hgt, -1);
    ms(memo, -1);
    ms(ans, INF);
    frr(i, idd){
        if(hgt[i] == -1){
            hgt[i] = 0;
            dfslca(i);
        }
    }
    for(auto p: st){
        pii cp = p;
        swap(cp.first, cp.second);
        printf("%f\n", sqrt(lca(id[p], id[cp])));
    }
}
