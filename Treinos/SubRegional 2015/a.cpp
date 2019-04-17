// https://www.urionlinejudge.com.br/judge/en/problems/origin/94

#include "bits/stdc++.h"
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

#define gnl cout << endl
#define olar cout << "olar" << endl
#define otp(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vii nodes[10400],nodes2[10400];
int dist[10400];

void dijkstra(){

	ms(dist,INF);
	dist[1]=0;
	set<pii> fila;

	fila.insert(mp(0,1));

	while(!fila.empty()){

		pii atual = *fila.begin();
		fila.erase(fila.begin());

		int cp=atual.fst;
		int idp=atual.snd;

		for(auto x : nodes2[idp]){

			if(dist[x.snd]> cp+x.fst){
			
				dist[x.snd]=cp+x.fst;
				fila.insert(mp(dist[x.snd],x.snd));
			
			}
		}

	}

}

int main(){

	int c,v;
	cin >> c >> v;

	fr(i,v){
		int x,y,w;
		cin >> x >> y >> w;
		nodes[x].pb(mp(w,y));
		nodes[y].pb(mp(w,x));
	}

	frr(i,c){
		for(auto x : nodes[i]){
			for(auto y : nodes[x.snd]){
				pii aux;
				aux.snd=y.snd;
				aux.fst=x.fst+y.fst;
				nodes2[i].pb(aux);
			}
		}
	}

	dijkstra();

	if(dist[c]==INF)
		cout << -1 << endl;
	else
		cout << dist[c] << endl;

}