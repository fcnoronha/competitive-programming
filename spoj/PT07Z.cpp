// https://www.spoj.com/problems/PT07Z/
#include<bits/stdc++.h>
using namespace std;

int n, u, v;

int main(){
	cin >> n;
	vector<int> adj[n+1];
	vector<int> dist(n+1, 0);
	vector<bool> v1(n+1, false);
	vector<bool> v2(n+1, false);
	vector<int> dist2(n+1, 0);

	int grr = n;

	if(n <= 1){
		cout << "0" << endl;
		return 0;
	}

	n--;
	while(n--){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while(!q.empty()){
		v = q.front();
		q.pop();
		if(v1[v]) continue;
		v1[v] = true;
		for(int u : adj[v]){
			q.push(u);
			dist[u] = dist[v] + 1;
		}
	}

	int mx = 0;
	for(int i = 0; i < grr; i++){
		if(dist[i] > dist[mx]) mx = i;
	}

	q.push(mx);
	dist2[mx] = 0;
	while(!q.empty()){
		v = q.front();
		q.pop();
		if(v2[v]) continue;
		v2[v] = true;
		for(int u : adj[v]){
			q.push(u);
			dist2[u] = dist2[v] + 1;
		}
	}

	cout << *max_element(dist2.begin(), dist2.end()) << endl;
}	