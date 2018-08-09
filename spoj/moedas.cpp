// http://br.spoj.com/problems/MOEDAS/

#include<bits/stdc++.h>
using namespace std;

int m, n, v;
int inf = 60000;

int main(){
	cin >> m;
	while(m != 0){
		vector<int> val;
		int qtd[50001];

		cin >> n;

		for(int i = 0; i < n; i++){
			cin >> v;
			val.push_back(v);	
		}

		qtd[0] = 0;
		for(int i = 1; i <= m; i ++){
			qtd[i] = inf;
			int qtd_min = inf;

			for(int j = 0; j < val.size(); j++){
				
				if(val[j] == i){
					qtd[i] = 1;
					break;
				}
				else if(val[j] < i){
					qtd_min = min(qtd_min, qtd[i - val[j]]);
				}
			}

			qtd[i] = min(qtd[i], qtd_min + 1);
		}

		if(qtd[m] >= inf){
			cout << "Impossivel" << endl;
		}
		else{
			cout << qtd[m] << endl;
		}

		cin >> m;
	}
}