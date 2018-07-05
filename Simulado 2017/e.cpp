#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 100100

int main(){

	long long int s,n,dt,l,delay,t0,tf;
	vector<pair<long long int,long long int>> work;
	cin >> n >> s;

	for(int i=0;i<n;i++){
		cin >> dt >> l;
		work.push_back(make_pair(dt,l));
	}

	sort(work.begin(),work.end());

	t0=s;
	delay=0;
	for(int i=0;i<n;i++){
		tf=t0+work[i].first;
		delay+=tf-work[i].second;
		t0=tf;
	}

	cout << delay << endl;

	return 0;
}