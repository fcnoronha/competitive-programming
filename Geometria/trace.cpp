// http://codeforces.com/problemset/problem/157/B

#include<bits/stdc++.h>
using namespace std;

const double PI = 3.141592653589793238463;

int main(){
	int n, x;
	vector<int> r;

	cin >> n;
	while(n--){
		cin >> x;
		r.push_back(x);
	}

	double res = 0.0;
	sort(r.begin(), r.end());
	int i = 0;

	if(r.size() % 2 == 1){
		i = 1;
		res += r[0]*r[0]*1.0;
	}

	for(i; i+1 < r.size(); i += 2){
		res += r[i+1]*r[i+1]*1.0 - r[i]*r[i]*1.0;
	}

	res *= PI;

	cout << setprecision(50) << res << endl;
}