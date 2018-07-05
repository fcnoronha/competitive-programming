#include<bits/stdc++.h>
using namespace std;

int a[100002], res[100002], n, x;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x;
		a[x]++;
	}

	vector<int> tei;
	for(int i = 1; i <= 100000; i++){
			if(a[i] != 0) tei.push_back(a[i]*i);
	}

	for(int i = tei.size()-1; i >= 0; i--){
		res[i] = 0;
		if(i+1 >= tei.size() || i == tei.size()) res[i] = tei[i];
		else if(i+2 == tei.size()) res[i] = tei[i] + res[i+2];
		else res[i] = tei[i] + max(res[i+2], res[i+1]);
	}

	cout << max(res[0], res[1]) << endl;
}

//VE OQ TA ERRADO AI VACILAO

//LOGICA DE IR PERCORREDNO DE TRAS PRA FRENTE E PEGANDO MAIOR VALOR

//a logica esta certa, so tem que refinar os if das condicionais