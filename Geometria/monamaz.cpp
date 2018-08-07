// https://br.spoj.com/problems/MONAMAZ/

#include<bits/stdc++.h>
using namespace std;

int x[1001], y[1001], mp[1001][3], n, t, i, j;
double dist[1001][2];

struct a{
	int n, x, y, d1, d2;
	struct a* mp1;
	struct a* mp2;
}ant[1001];

int main(){
	while (cin >> n && n != 0){
		t++; 
		bool BotoFe = true;

		for (i = 0; i < n; i++) cin >> ant[i].x >> ant[i].y, ant[i].n = i;

		for (i = 0; i < n; i++) for (j = 0; j < n; j++){
			if (j != i){
				int d = (int)sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
				if (mp[i][0] == 0) dist[i][0] = d, mp[i][1] = j, mp[i][0] = 1;
				else if (mp[i][0] == 1) dist[i][1] = d, mp[i][2] = j, mp[i][0] = 2;
				else if (mp[i][0] == 2){
					if (d == dist[i][0] && (x[j] <= x[mp[i][1]] || (x[j] <= x[mp[i][1]] && y[j] <= y[mp[i][1]])))
						mp[i][1] = j;
					else if (d == dist[i][1] && (x[j] <= x[mp[i][2]] || (x[j] <= x[mp[i][2]] && y[j] <= y[mp[i][2]])))
						mp[i][2] = j;
					else if (dist[i][0] == min(dist[i][0], dist[i][1]) && d < dist[i][1]) dist[i][1] = d, mp[i][2] = j;
					else if (dist[i][1] == min(dist[i][0], dist[i][1]) && d < dist[i][0]) dist[i][0] = d, mp[i][1] = j;
				}
			} 
		}

		for (i = 0; i < n; i++) for (j = 1; j < 3; j++) {
			if (mp[i][j] != -1){
				int ant = mp[i][j];
				if (mp[ant][1] != i && mp[ant][2] != i) BotoFe = false;
			}
		}

		(BotoFe)? cout << "All stations are reachable." << endl : cout << "There are stations that are unreachable." << endl;
	}
}

// Fazer as paradinhas que faltam usando a struct