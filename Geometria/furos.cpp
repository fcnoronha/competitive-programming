// https://br.spoj.com/problems/FUROS/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t = 0, n, x[4002], y[8922];
	double ans, anss;

	while (cin >> n && n != 0){
		ans = 0; t++;
		anss = DBL_MAX;
		for (int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i != j)
					ans = max(ans, sqrt(pow(x[i]-x[j], 2.0) + pow(y[i]-y[j], 2.0))*2.0);
			}
			anss = min(anss, ans);
		}

		cout << "Teste " << t << endl << floor(anss + 6.0) << endl << endl;
	}
}