// http://codeforces.com/problemset/problem/854/A

#include <bits/stdc++.h>
using namespace std;


int gdc(int a, int b){
	if(a == 0) return b;

	return gdc(b%a, a);
}

int n, a, b;

int main(){
	cin >> n;
	bool pronto = false;

	a = n/2;
	b = n-a;

	while (!pronto && a <= n/2){
		if(gdc(a,b) == 1) pronto = true;
		else{
			a--;
			b++;
		}	
	}

	cout << a << " " << b << endl;
}