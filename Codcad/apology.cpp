// codcad.com/problem/82

#include<bits/stdc++.h>
using namespace std;

int c, f, contador, maxd;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> c >> f;

	while(c != 0 and f != 0){
		contador ++;
		vector< pair<int,int> > val;

		for(int i = 0; i < f; i++){
			int a, b;
			cin >> a >> b;
			maxd += a;
			val.push_back(make_pair(a, b));
		}

		sort(val.begin(), val.end());

		int res[f+1][c+1];

		//val.fist == peso
		//val.second == valor
		//f == numero de elementos
		//c == peso max

		for(int i = 0; i <= f; i++){
			for(int j = 0; j <= c; j++){
				res[i][j] = 0;
				if(i == 0 or j == 0){
					res[i][j] = 0;
				}
				else if(val[i-1].first <= j){
					res[i][j] = max(val[i-1].second + res[i-1][j - val[i-1].first], res[i-1][j]);
				}
				else{
					res[i][j] = res[i-1][j];
				}
			}
		}

		cout << "Teste " << contador << endl << res[f][c] << endl << endl;

		cin >> c >> f;
	}
}