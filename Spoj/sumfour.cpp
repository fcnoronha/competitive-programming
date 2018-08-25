// https://www.spoj.com/problems/SUMFOUR/
#include<bits/stdc++.h>
using namespace std;

long long int n,a[2501],b[2501],c[2501],d[2501],r;
vector<long long int> ab, cd;

int main(){
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ab.push_back(a[i]+b[j]);
			cd.push_back(c[i]+d[j]);
		}
	}
	sort(cd.begin(), cd.end());
	for(long long int u : ab){
		if(binary_search(cd.begin(), cd.end(), -u)){
			int i = (lower_bound(cd.begin(), cd.end(), -u) - cd.begin());
			int j = (upper_bound(cd.begin(), cd.end(), -u) - cd.begin());

			r += j-i;
		} 
	}	

	cout << r << endl;
}