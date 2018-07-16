// http://codeforces.com/problemset/problem/275/A

#include <bits/stdc++.h>
using namespace std;

int g[3][3], r[5][5];

int main(){

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> g[i][j];
			r[i][j] = 1;
		}
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			
			if(g[i][j] % 2 != 0){
				r[i][j] = (r[i][j] + 1) % 2;
				if(i + 1 >= 0 && i+1 < 3) r[i+1][j] = (r[i+1][j] + 1) % 2;
				if(i - 1 >= 0 && i-1 < 3) r[i-1][j] = (r[i-1][j] + 1) % 2;
				if(j + 1 >= 0 && j+1 < 3)r[i][j+1] = (r[i][j+1] + 1) % 2;
				if(j - 1 >= 0 && j-1 < 3)r[i][j-1] = (r[i][j-1] + 1) % 2;
			}
		}
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << r[i][j];
		}
		cout << endl;
	}
}