// http://acm.timus.ru/problem.aspx?num=1709

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

typedef struct {
    int d;
    int u, v;
} aresta;

bool comp(aresta a, aresta b){ 
	return a.d < b.d; 
}

#define MAXN 102 
#define MAXM 10009 

aresta aa[MAXN][MAXN];

int id[MAXN];
int sz[MAXN];

aresta mst[MAXM];

int find(int x){
    if(id[x] == x) return x;
    return id[x] = find(id[x]);
}

void join(int a, int b){    
    a = find(a);
    b = find(b);
    
    if (sz[a] < sz[b]) id[a] = b;
    else if (sz[b] < sz[a]) id[b] = a;
    else {
        id[a] = b;
        sz[b]++;
    }    
}

int main(){
	fastio;
	int n, d, a; 
	cin >> n >> d >> a;

	fr(i, n) id[i] = i;

	fr(i, n)
		fr(j, n) 
			aa[i][j].u = i, aa[i][j].v = j, aa[i][j].d = a;

	vector< vector<char> > map;
	fr(i, n){
		vector<char> st(n);
		string aux;
		cin >> aux;
		fr(j, n){
			if(aux[j] == '1') aa[i][j].d = 0;
			st[j] = aux[j];
		}
		map.pb(st);
	}

	vector<aresta> oi;
	fr(i, n){
		fr(j, i){
			int aux = !(map[i][j] == '1');
			aux *= a;
			oi.pb({aux, i, j});
		}
	}
			
	fr(i, n) fr(j, n) map[i][j] = '0';

	sort(oi.begin(), oi.end(), comp);

	ll ans = 0;
	fr(i, oi.size()){
		int u = oi[i].u;
		int v = oi[i].v;

		if(find(u) != find(v)){
			join(u, v);
			ans += oi[i].d;

			if (oi[i].d == 0)
				map[u][v] = map[v][u] = '0';

			else if (oi[i].d == a)
				map[u][v] = map[v][u] = 'a';
		}
		else{
			if (oi[i].d == 0){
				ans += d;
				map[u][v] = map[v][u] = 'd';
			}
		}
	}

	fr(i, n){
		fr(j, n){
			if (map[i][j] == '1'){
				map[i][j] = map[j][i] = 'd';
				ans += d;
			}
		}
	}
	
	cout << ans << endl;
	
	fr(i, n){
		fr(j, n){
			cout << map[i][j];
		}
		cout << endl;
	}

}
