// https://br.spoj.com/problems/DESVRUA/

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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define MAXN 10009 

vector<int> adj[MAXN];				  
vector<int> time_in; 				  
vector<int> back;     				
vector< pair<int,int> > cut_edge;    

int time_spent;

void dfs (int v, int parent){
	back[v] = time_in[v] = ++time_spent; 

	for (int u : adj[v]){
		int next = u;

		if (next == parent) 
			continue; 

		if (time_in[next] == -1){
			dfs(next, v);

			if (back[next] > time_in[v])
				cut_edge.push_back({v, next});

			back[v] = min(back[v], back[next]); 
		}
		else {
			back[v] = min(back[v], time_in[next]);
		}
	}
}

int main(){
	int n, m;

	cin >> n >> m;

	time_spent = 0;
	time_in.assign(n+2, -1); // Similar to fill
	back.assign(n+2, -1);

	int a, b, c;
	cin >> a >> b >> c;
	fr(i, m-1){
		cin >> a >> b >> c;
		adj[a].pb(b);
		if (c == 2) adj[b].pb(a);
	}

	for (int i = 1; i <= n; i++)
		if (time_in[i] == -1)
			dfs(i, -1);

	for (pair<int,int> i : cut_edge)
		cout << i.first << " " << i.second << endl;

}