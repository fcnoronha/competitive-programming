// http://codeforces.com/problemset/problem/961/B

#include<bits/stdc++.h>
using namespace std;

int n, k;
int main(){
	cin >> n >> k;
	long long int a[n+2];

	vector<long long int> acor(n+2,0);
	vector<long long int> dorm(n+2,0);

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int t[n+2];
	for(int i = 1; i <= n; i++){
		cin >> t[i];
	}

	for(int i = 1; i <= n; i++){
		if(t[i] == 1){
			acor[i] = a[i];
			if(i > 0) acor[i] += acor[i-1], dorm[i] = dorm[i-1];
		}
		else{
			dorm[i] = a[i];
			if(i > 0) dorm[i] += dorm[i-1], acor[i] = acor[i-1];
		}
	}

	long long int mx = 0;
	for(int i = 0; i <= n-k; i++){
		mx = max(mx, dorm[i+k] - dorm[i]);
	}

	cout << mx+acor[n] << endl;
}