#include<bits/stdc++.h>
using namespace std;

int n, m, le[61], ld[61], total;
char l;

int main(){	
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> m >> l;

		if(l == 'E') le[m] += 1;
		else ld[m] += 1;
	}

	for(int j = 30; j < 61; j++){
		total += min(ld[j], le[j]);
	}

	cout << total << endl;
}