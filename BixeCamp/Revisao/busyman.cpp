// https://www.spoj.com/problems/BUSYMAN/
#include<bits/stdc++.h>
using namespace std;

long long int t, n, i, f, r, max_ini;

int main(){
	cin >> t;
	while(t--){
		r = 0;
		cin >> n;
		vector<pair<int, int> > h;
		while(n--){
			cin >> i >> f;
			h.push_back(make_pair(f, i));
			max_ini = max(max_ini, i);
		}
		sort(h.begin(), h.end());
		
		long long int ini = 0, fim = 0, j = 0;

		for(int j = 0; j < h.size(); j++){
			if(h[j].second >= fim){
				r++;
				ini = h[j].second;
				fim = h[j].first;
			}
		}

		cout << r << endl;
	}
}