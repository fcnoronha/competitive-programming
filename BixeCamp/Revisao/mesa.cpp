// https://br.spoj.com/problems/MESA/
#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	int t = 1;
	int n,m;
	while(cin >> n){
		cin >> m;
		
		int u, v;
		vector<int> pos(n+1, 0);
		vector<int> adj[n+1];
		queue<int> q;

		while(m--){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool haha = true;
		
		for(int i = 1; i < pos.size(); i++){
			if(pos[i] != 0) continue;
			q.push(i);
			pos[i] = 1;
			while(!q.empty()){
				int v = q.front();
				q.pop();
				for(int u : adj[v]){
					if(pos[u] == 0){
						pos[u] = -pos[v];
						q.push(u);
					}
					else if(pos[u] == pos[v]) haha = false;
				}				
			}
		}
		
		cout << "Instancia " << t << endl;
		t++;
		if(haha) cout << "sim" << endl << endl;
		else cout << "nao" << endl << endl;
	}
}