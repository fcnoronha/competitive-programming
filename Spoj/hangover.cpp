// https://www.spoj.com/problems/HANGOVER/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int ans, div;
	double c, sum;

	while (cin >> c && c != 0.00){
		ans = 1;
		sum = 0.00;

		while (sum < c){
			ans++;
			sum += 1.0/ans;
			//sum = (int)(sum * 100.0)/100.0;
		}

		cout << ans-1 << " card(s)" << endl;
	}

}