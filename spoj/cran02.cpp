// https://www.spoj.com/problems/CRAN02/
#include<bits/stdc++.h>
using namespace std;

int t, n, x;
long long int s = 0, r = 0;

int main(){
	cin >> t;
	while(t--){
		s = r = 0;
		cin >> n;

		vector<int> a(10000001, 0);
		vector<int> b(10000001, 0);


		while(n--){
			cin >> x;
			s += x;
			if(s >= 0) a[s] ++;
			else b[abs(s)] ++;
		}
		a[0]++;

		for(int i = 0; i < 10000000; i++){
			while(a[i]--) r += a[i];
			while(b[i]--) r += b[i];
		}

		cout << r << endl;
	}
}