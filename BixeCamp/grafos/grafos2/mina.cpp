#include <bits/stdc++.h>
using namespace std;

int n, grid[101][101], tempo[101][101];
vector<int> adj[5];

int main(){
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
			tempo[i][j] = -1;
		}
	}

	cout << tempo[n-1][n-1] << endl;
}