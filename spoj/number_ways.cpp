// http://codeforces.com/problemset/problem/466/C

#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin >> n;
	long long int a[n+1];
	int uni[n+1];

	for(int i = 0; i < n; i++){
		cin >> a[i];
		uni[i] = a[i];
		if(i > 0) a[i] += a[i-1]; 
	}

	if(a[n-1] % 3 != 0){
		cout << "0" << endl;
		return 0;
	}

	long long int div = a[n-1]/3;
	long long int sum = 0, acu = 0;

	for(int i = 0; i < n-1; i++){
		if(a[i] == div*2) sum += acu;
		if(a[i] == div) acu++;
	}

	cout << sum << endl;
}