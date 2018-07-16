// http://codeforces.com/contest/659/problem/D

#include <bits/stdc++.h>
using namespace std;


int n, x[1002], y[1002];

int main(){
	cin >> n;

	for(int i = 0; i < n+1; i++){
		cin >> x[i] >> y[i];
	}


	cout << n/2 - 2 << endl;
}