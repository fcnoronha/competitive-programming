#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, n, d;

	cin >> n >> d >> a;

	if(d > a){
		cout << d - a << endl;
	}
	else if(d == a){
		cout << "0" << endl;
	}
	else{
		cout << (n - (a - d)) << endl;
	}
}