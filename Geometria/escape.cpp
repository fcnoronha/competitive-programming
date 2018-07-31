// http://codeforces.com/contest/932/problem/F

#include<bits/stdc++.h>
using namespace std;


int main(){
	
	int n, i;
	cin >> n;

	vector<long long int> a(n+1, 0);
	vector<long long int> b(n+1, 0);
	vector<long long int> dist(n+1, LLONG_MAX);
	vector<bool> folha(n+1, true);
	vector<int> adj[n+1];

	for(i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(i = 1; i <= n; i++){
		cin >> b[i];
	}

	long long int x, y;

	for(i = 0; i < n-1; i++){
		cin >> x >> y;
		adj[max(x,y)].push_back(min(x,y));
		//adj[y].push_back(x);
		folha[min(x,y)] = false;
	}

	for(i = 1; i <= n; i++){
		if(folha[i]) dist[i] = 0;
	}

	for(i = 1; i <= n; i++){
		if(folha[i]){
			vector<bool> visited(n+1, false);
			priority_queue<pair<long long int,int> > q;
			q.push(make_pair(0, i));
			
			while(!q.empty()){
				int v = q.top().second;
				q.pop();
				if(visited[v]) continue;
				visited[v] = true;

				for(int u : adj[v]){
					if(dist[u] > min(dist[v] + a[u]*b[v], a[u]*b[i])){
						dist[u] = min(dist[v] + a[u]*b[v], a[u]*b[i]);
						q.push(make_pair(-dist[u], u));
					}
				}
			}
		}
	}

	for(i = 1; i <= n; i++){
		if(folha[i]) dist[i] = 0;
	}

	for(i = 1; i <= n; i++) cout << dist[i] << " ";
	cout << endl;
}

// nao sei montar uma arvore de tal maneira que eu cosniga percorrer de
// um "no filho" para um 'no pai'