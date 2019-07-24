#include <bits/stdc++.h>
using namespace std;

int n, i[10000], soma = 0, somai = 0, impar = 0, anti = 100000;

int main(){
cin >> n;
	for(int x = 0; x < n; x++) {
		cin >> i[x];
		if(i[x]%2 == 0) {
			soma = soma + i[x];
		}
		else {
			somai = somai + i[x];
			impar++;
			if(i[x] < anti) {
			  anti = i[x];
			}
			
	}
	if(impar%2== 0) {
			  soma += somai;
			}
			else {
			  soma += (somai - anti);
			}
}
	cout << soma << endl;
}
