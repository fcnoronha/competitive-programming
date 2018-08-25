// http://codeforces.com/problemset/problem/20/C

#include<bits/stdc++.h>
using namespace std;

int inf = INT_MAX;
int n, m, a , b, x, ori[100001], visited[100001];

int main(){
	cin >> n >> m;

	vector<long long int> dist(n+2, inf);
	vector<pair<int, long long int> > w[100001];

	for(int i = 0; i < m; i++){
		cin >> a >> b >> x;
		w[a].push_back(make_pair(b,x));
		w[b].push_back(make_pair(a,x));
	}

	priority_queue<pair<int,int> > q;
	q.push(make_pair(0, 1));
	dist[1] = 0;
	ori[1] = 1;

	while(!q.empty()){
		int v = q.top().second;
		q.pop();

		if(visited[v] == 1) continue;
		visited[v] = 1;

		for(pair<int, long long int> u : w[v]){
			int ver = u.first;
			if(dist[ver] > dist[v] + u.second){
				dist[ver] = dist[v] + u.second;
				q.push(make_pair(-dist[ver], ver));
				ori[ver] = v;
			}
		}
	}

	stack<int> res;

	int c = n;
	if(dist[c] == inf) cout << "-1";
	else{
		res.push(c);
		while(ori[c] != 1){
			res.push(ori[c]);
			c = ori[c];
		}
		res.push(1);
	}
	
	while(!res.empty()){
		int r = res.top();
		cout << r << " ";
		res.pop();
	}

	cout << endl;
}

// esta dando wa no teste 31