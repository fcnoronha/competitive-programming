// http://codeforces.com/problemset/problem/702/C
#include<bits/stdc++.h>
using namespace std;

long long int x, mx, mn, r, n, m;

int main(){

	cin >> n >> m;

	vector<long long int> cid;
	vector<long long int> ant;

	while(n--){
		cin >> x;
		cid.push_back(x);
	}

	while(m--){
		cin >> x;
		ant.push_back(x);
		mn = min(mn, x);
		mx = max(mx, x);
	}

	for(int i = 0; i < cid.size(); i++){ 
		long long int esq = *(lower_bound(ant.begin(), ant.end(), cid[i]) - 1);
		long long int dir = *(upper_bound(ant.begin(), ant.end(), cid[i]));

		if(cid[i] > mx) dir = LLONG_MAX;
		if(cid[i] < mn) esq = LLONG_MIN;

		//cout << endl << esq << " " << dir << endl;

		long long int dis = min(abs(cid[i] - dir), abs(cid[i] - esq));
		if(binary_search(ant.begin(), ant.end(), cid[i])) dis = 0;
		r = max(r, dis);
	}

	cout << r << endl;
}