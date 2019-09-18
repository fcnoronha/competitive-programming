#include "bits/stdc++.h"
using namespace std;

vector<int> v;

int main(){

	int n; cin >> n;

	bool flag= true;

	int carlos;
	cin >> carlos;

	for(int i=0;i<n-1;i++){
		int k; cin >> k;
		if(k>carlos)
			flag=false;
	}

	cout << (flag ? "S" : "N") << endl;

}