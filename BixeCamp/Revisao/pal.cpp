// https://br.spoj.com/problems/PAL/
#include<bits/stdc++.h>
using namespace std;

int t, n;
string s;

int main(){
	t = 1;
	while(cin >> n && n != 0){
		cin >> s;

		int corte[n];
		bool pal[n][n];

		int i, j, k, l;

		for(i = 0; i < n; i++){
			pal[i][i] = true;
		}

		for(l = 2; l <= n; l++){
			for(i = 0; i < n-l+1; i++){
				j = i+l-1;
				if(l == 2) pal[i][j] = (s[i] == s[j]);
				else pal[i][j] = (s[i] == s[j]) && pal[i+1][j-1];
			}			
		}

		for(i = 0; i < n; i++){
			if(pal[0][i]) corte[i] = 0;
			else{
				corte[i] = INT_MAX;
				for(j = 0; j < i; j++){
					if(pal[j+1][i] && 1+corte[j] < corte[i]) corte[i] = 1 + corte[j];
				}
			}
		}

		cout << "Teste " << t << endl << corte[n-1]+1 << endl << endl;
		t++;
	}
}