// https://br.spoj.com/problems/PARPROX/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	long double x[n], y[n], ans;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	ans = LDBL_MAX;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if(j != i) ans = min(ans, sqrt(pow(x[i]-x[j], 2.0) + pow(y[i]-y[j], 2.0)));
		}
	}

	cout << fixed << setprecision(3) << ans << endl;
}

