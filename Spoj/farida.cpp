// https://www.spoj.com/problems/FARIDA/
#include<bits/stdc++.h>
using namespace std;

int t, n;
long long int r, x;

int main(){
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		long long int a = 0, aa = 0;
		while(n--){
			cin >> x;
			r = max(aa+x, a);
			aa = a;
			a = r;
		}
		cout << "Case " << i << ": " << max(a, aa) << endl;
	}
}