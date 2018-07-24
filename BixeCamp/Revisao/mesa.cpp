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
		vector<int> adj[n+1];
		int u, v;
		vector<int> pos(n+1, 0);

		while(m--){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		pos[1] = 1;

		bool haha = true;
		for(int i = 1; i <= n; i++){
			for(int u : adj[i]){
				if(pos[u] == 0) pos[u] = -pos[i];
				else if(pos[u] == pos[i]) haha = false;
			}
		}
		
		cout << "Instancia " << t << endl;
		t++;
		if(haha) cout << "sim" << endl << endl;
		else cout << "nao" << endl << endl;
	}
}