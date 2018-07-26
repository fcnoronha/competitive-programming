// https://www.spoj.com/problems/ESJAIL/
#include<bits/stdc++.h>
using namespace std;

int n, k, m, a, b;

int main(){
	cin >> n >> k >> m;
	int abre[100001];
	bool visitavel[100001];
	bool visitado[100001];

	while(n != -1 && k != -1 && m != -1){
		fill(abre, abre+n+1, 0);
		fill(visitavel, visitavel+n+1, true);
		fill(visitado, visitado+n+1, false);

		vector<int> adj[n+1];

		for(int i = 0; i < k; i++){
			cin >> a >> b;	
			abre[a] = b;
			visitavel[b] = false;
		}

		for(int i = 0; i < m; i++){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		//bool engracadoeim = false;

		queue<int> q;
		q.push(1);
		int v = 0;
		while(!q.empty()){
			v = q.front();
			q.pop();
			if(abre[v] != 0){
				visitavel[abre[v]] = true;
				if(visitado[abre[v]]) q.push(abre[v]);
				abre[v] = 0;
				//fill(visitado.begin(), visitado.end(), false);
			}
			for(int u : adj[v]){
				if(visitado[u]) continue;
				visitado[u] = true;
				if(visitavel[u]) q.push(u);
			}
		}

		if(visitado[n] && visitavel[n]) cout << "Y" << endl;
		else cout << "N" << endl;

		cin >> n >> k >> m;
	}
}