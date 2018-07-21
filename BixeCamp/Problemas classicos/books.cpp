// http://codeforces.com/problemset/problem/279/B

#include<bits/stdc++.h>
using namespace std;

int n, i, j, m;

int main(){
	cin >> n >> m;
	long long int v[n+2];

	for(int i = 1; i <= n; i++){
		cin >> v[i];
		if(i > 0) v[i] += v[i-1];
	}

	//BB para achar o indice do primeiro elemento maior ou igual oq eu quero(v[i] - m)
	int maxi = 0;
	for(int i = n; i >= 0; i--){
		int ini = 0, fim = i;
		while(ini != fim){
			int meio = (ini+fim)/2;
			if(v[meio] < v[i] - m) ini = meio+1;
			else fim = meio;
		}
		//cout << fim << endl;
		maxi = max(i-fim, maxi);
	}

	cout << maxi << endl;
}