#include<bits/stdc++.h>
using namespace std;

int v, num, x;
vector<int> m;

int main(){
	cin >> v >> num;

	for(int i = 0; i < num; i++){
		cin >> x;
		m.push_back(x);
	}

	int res[num+1][v+1];

	for(int i = 0; i <= num; i++){
		for(int j = 0; j <= v; j++){
			if(i == 0 or j == 0)
				res[i][j] = 0;
			else if(m[i-1] <= j)
				res[i][j] = max(m[i-1] + res[i-1][j-m[i-1]], res[i-1][j]);
			else
				res[i][j] = res[i-1][j];
		}
	}

	if(res[num][v] == v)
		cout << "S" << endl;
	else
		cout << "N" << endl;	
}