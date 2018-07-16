// http://codeforces.com/problemset/problem/854/A

#include <bits/stdc++.h>
using namespace std;

int n, t[10];
string x;

int main(){
	cin >> n;

	for(int i = 0; i < 4; i++){
		cin >> x;
		for(int j = 0; j < 4; j++){			
			if(x[j] != '.') t[(int)x[j] - 48]++;
		}		
	}

	bool r = true;
	for(int i = 1; i < 10; i++){
		if(t[i] > n*2) r = false;
	}

	if(r) cout << "YES" << endl;
	else cout << "NO" << endl;
}