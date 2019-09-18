#include "bits/stdc++.h"
using namespace std;

vector<int> v;

int main(){

	long long int n,k;
	cin >> n >> k;

	for(long long int i=1;i<10;i++){
		long long int val = (k*n*i + 9ll)/10ll;
		cout << val;
		if(i!=9)
			cout << " ";
	}

	cout << endl;


}