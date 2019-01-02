// https://codeforces.com/contest/988/problem/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

int k, n, a[101];
vector<int> v;
vector<int> r;

int main(){
	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];

		if(k > 0){
			sort(v.begin(), v.end());
			if(!(binary_search(v.begin(), v.end(), a[i]))){
				r.pb(i+1);
				v.pb(a[i]);
				k--;
			}
		}
	}

	if(k == 0){
		cout << "YES" << endl;
		fr(i, r.size()){
			cout << r[i] << " ";;
		}
		cout << endl;
	}

	else cout << "NO" << endl;
}

