// https://www.spoj.com/problems/UPDATEIT/
#include<bits/stdc++.h>
using namespace std;

int t, q, n, u, l, r, v, i;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> u;
		vector<long long int> vec(n+2, 0);
		vector<long long int> res(n+1);

		while(u--){
			cin >> l >> r >> v;
			vec[l] += v;
			vec[r+1] += -v;
		}

		long long int r = 0;
		for(int j = 0; j < n; j++) r += vec[j], res[j] = r;

		cin >> q;
		while(q--){
			cin >> i;
			cout << res[i] << endl;
		}
	}
}