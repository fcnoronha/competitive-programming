// http://codeforces.com/problemset/problem/466/C

#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin >> n;
	long long int a[n+2];
	int uni[n+2];

	a[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		uni[i] = a[i];
		a[i] += a[i-1]; 
	}

	long long int div = a[n]/3;
	bool soma = true;
	int sum = 0;

	//testando pra primeira subarray
	int i = n;
	while(a[i] != div && soma){
		if(i == 0) soma = false;
		i--;
	}
	if(a[i] == div){
		sum++;
		int k = i+1;
		while(uni[k] == 0){
			k++;
			sum++;
		}	
		k = i-1;
		while(uni[k] == 0){
			k--;
			//sum++;
		}	
	} 

	//testando pra ultima subarray
	int j = n-1;
	while(a[n]-a[j] != div && soma){
		if(j == 0) soma = false;
		j--;
	}
	if(a[n]-a[j] == div){
		sum++;
		int k = j+1;
		while(uni[k] == 0){
			k++;
			sum++;
		}	
		k = j-1;
		while(uni[k] == 0){
			k--;
			//sum++;
		}	
	} 

	if(soma) cout << sum << endl;
	else cout << 0 << endl;

	//arruma ai: ideia de incrementar 1 quando o começo/fim da array tem 0's
}