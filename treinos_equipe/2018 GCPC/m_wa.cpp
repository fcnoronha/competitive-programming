#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(iii, x.size()) cout << x[iii] << " \n"[iii==x.size()-1]
#define pvv(x, n) for(int iii = 1, vaca = nnn; i <= nnn;i++) cout << x[i] << " \n"[iii==nnn];

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
const int N = 5e2 + 1;
const int LMAXN = 19;

int pai[N*N], peso[N*N];
int xx[] = {1, 0, -1, 0};
int yy[] = {0, -1, 0, 1};
int m, n;

vi adj[N*N];

int node(int i, int j){
    return i + j*m;
}

bool inrange(int a, int lim){
    return (a >= 0 && a < lim );
}

int find(int x){
	return (pai[x] == x)?x:(pai[x] = find(pai[x]));
}

void join(int x, int y){
	if((x = find(x)) == (y = find(y))) return;

	if(peso[x] > peso[y]) swap(x, y);

	pai[x] = y;
	if(peso[x] == peso[y]) peso[y]++;
}

int grid[N][N];

bool mycomp(pair<pii, int> a, pair<pii, int> b){
    return a.second < b.second;
}

int memo[N*N][LMAXN + 1];
int hgt[N*N];
int sp[N*N][LMAXN+1];
int nw[N*N];

void dfslca(int v){

	for(auto filho : adj[v]){

		if(hgt[filho] != -1)	continue;

		memo[filho][0]=v;		//seta o pai do cara
		hgt[filho]=hgt[v]+1;
        sp[filho][0] = max(nw[filho], nw[v]);

		for(int i=1;i<LMAXN;i++){
			if(memo[filho][i-1] != -1){
                memo[filho][i]=memo[memo[filho][i-1]][i-1];
                sp[filho][i]=max(sp[sp[filho][i-1]][i-1], sp[filho][i-1]);
            }
        }
								//gera a sparse table na propria dfs (dependencias ja estao calculadas, por inducao)
		dfslca(filho);
	}

}

int lca(int a, int b){
    int ans = -1;

	if(hgt[a]<hgt[b])	swap(a,b);		//quero que a seja o cara mais profundo na arvore

	for(int i=LMAXN-1; i>=0; i-- ){						//bota a e b na mesma altura
		if(memo[a][i] != -1 && hgt[memo[a][i]] >= hgt[b]) ans = max(sp[a][i], ans), a=memo[a][i];	//vou subir o a ate ele ficar no mesmo nivel do b
	}

	if(a==b)	return ans;

	for(int i=LMAXN-1; i>=0; i--){	//vai pulando ate ficarem ambos a e b um nivel antes do LCA
		if(memo[a][i] == -1 || memo[a][i] == memo[b][i]) continue;
        ans = max(sp[a][i], ans);
        ans = max(sp[b][i], ans)
        a=memo[a][i];
		b=memo[b][i];
	}

	return max(sp[b][0], max(sp[a][0], ans)) ;	//sobe um nivel e retorna o lca

}

vector<pii, int> nodes;

int main(){
    int q;
    fr(i, m){
        scanf("%d%d%d", &m, &n, &q);
        fr(j, n){
            scanf("%d", grid[i][j]);
            nodes.pb(mp(i, j), grid[i][j]);
        }
    }
    fr(i, m*n){
        pai[i] = i;
    }
    sort(nodes, mycomp);
    int ar = 0;
    for(auto p: nodes){
        fr(k, 4){
            int nx = p.f.f + xx[k]; int ny = p.f.s + yy[k];
            if(inrange(nx, m) && inrange(ny, n) && find[node(nx, ny)] != find[node(p.f.f, p.f.s)]){
                join(node(nx, ny), node(p.f.f, p.f.s));
                adj[node(p.f.f, p.f.s)].pb(node(nx, ny));
                adj[node(nx, ny)].pb(node(p.f.f, p.f.s);
                if(++ar = n*m - 1) break;
            }
        }
    }

    dfslca(0);
    while(q--){
        int a, c, d, b; scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", lca(node(a--, b--), node(c--, d--)));
    }
}
