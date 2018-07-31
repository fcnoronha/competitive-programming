// http://codeforces.com/problemset/problem/227/A

#include<bits/stdc++.h>
using namespace std;


int main(){
	
	pair<long long int, long long int> p;
	pair<long long int, long long int> q;
	pair<long long int, long long int> r;

	long long int a, b, val;

	cin >> a >> b;
	p = make_pair(a,b);

	cin >> a >> b;
	q = make_pair(a,b);

	cin >> a >> b;
	r = make_pair(a,b);


	val = (q.second - p.second) * (r.first - q.first) -
		(q.first - p.first) * (r.second - q.second);

	if(val == 0) cout << "TOWARDS" << endl;
	else if(val < 0) cout << "LEFT" << endl;
	else cout << "RIGHT" << endl;
}