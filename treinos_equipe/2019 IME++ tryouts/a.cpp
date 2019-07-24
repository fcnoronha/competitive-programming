// https://codeforces.com/gym/102254

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

vi adj[2020];
int dist[2020][2020];

void bfs(int src){

	ms(dist[src],0x3f3f3f3f);
	dist[src][src]=0;

	queue<int> q;
	q.push(src);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(dist[src][v]>1+dist[src][u]){
				dist[src][v]=1+dist[src][u];
				q.push(v);
			}
		}
	}

}

int main(){

	fastio

	int n,m;
	cin >> n >> m;
	fr(i,m){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	frr(i,n)
		bfs(i);

	int mn = 0;

	frr(i,n)
		frr(j,n)
			mn=max(mn,dist[i][j]);

	if(mn==0x3f3f3f3f)
		cout << "=[" << endl;
	else
		cout << "=] " << mn << endl;
}
