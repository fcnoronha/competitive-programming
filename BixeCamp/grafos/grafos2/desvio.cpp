#include <bits/stdc++.h>
using namespace std;

int n, m, c, k, w[100001][100001], visited[251];
vector<int> adj[100000];
int inf = INT_MAX;

int main(){
	cin >> n >> m >> c >> k;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
			tempo[i][j] = -1;
		}
	}

	cout << tempo[n-1][n-1] << endl;
}