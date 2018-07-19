#include<bits/stdc++.h>
using namespace std;

int n, x;

int main(){
	cin >> n;
	vector<long long int> a(100001, 0);

	for(int i = 0; i < n; i++){
		cin >> x;
		a[x] += x;
	}

	for(int i = 2; i < 100001; i++){
		a[i] = max(a[i-1], a[i] + a[i-2]);
	}

	cout << a[100000] << endl;
}