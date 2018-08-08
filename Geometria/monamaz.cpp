// https://br.spoj.com/problems/MONAMAZ/

#include<bits/stdc++.h>
using namespace std;

int x[1001], y[1001], mp[1001][3], n, t, i, j;
double dist[1001][2];
bool visited[1001];
	
struct a{
	int n, x, y;
	int d1, d2;
	struct a* mp1;
	struct a* mp2;
}ant[1001];

int main(){
	while (cin >> n && n != 0){
		t++; 
		bool BotoFe = true;
		fill (visited, visited+n, false);

		for (i = 0; i < n; i++) cin >> ant[i].x >> ant[i].y, ant[i].n = i;

		for (i = 0; i < n; i++) for (j = 0; j < n; j++){
			if (j != i){

				int d = pow(ant[i].x-ant[j].x, 2) + pow(ant[i].y-ant[j].y, 2);

				if (!ant[i].mp1) ant[i].mp1 = &ant[j], ant[i].d1 = d; // Caso ainda n tenha sido atribuido o primeiro mais perto
				
				else if (!ant[i].mp2) ant[i].mp2 = &ant[j], ant[i].d2 = d;
				
				else if (ant[i].d1 == ant[i].d2 && ant[i].d2 == d){
					int x1, x2, y1, y2;
					x1 = ant[i].mp1->x; y1 = ant[i].mp1->y;
					x2 = ant[i].mp2->x; y2 = ant[i].mp2->y;

					if (x1 < x2 || (x1 <= x2 && y1 < y2)){
						if (x1 < ant[j].x || (x1 <= ant[j].x && y1 < ant[j].y)){
							ant[i].mp1 = &ant[j];
							ant[i].d1 = d;
						}
					}
					else if (x2 < x1 || (x2 <= x1 && y2 < y1)){
						if (x2 < ant[j].x || (x2 <= ant[j].x && y2 < ant[j].y)){
							ant[i].mp2 = &ant[j];
							ant[i].d2 = d;
						}
					}
				}

				else if (min(ant[i].d1, d) == d){
					ant[i].mp1 = &ant[j];
					ant[i].d1 = d;
				}

				else if (min(ant[i].d2, d) == d){
					ant[i].mp2 = &ant[j];
					ant[i].d2 = d;
				}

				else if (min(ant[i].d1, ant[i].d2) == ant[i].d1 && ant[i].d1 > d){
					ant[i].d1 = d;
					ant[i].mp1 = &ant[j];
				}
				else if (min(ant[i].d1, ant[i].d2) == ant[i].d2 && ant[i].d2 > d){
					ant[i].d2 = d;
					ant[i].mp2 = &ant[j];
				}				
			} 
		}
		cout << "paupau" << endl;
		queue<int> q;
		q.push(0);
		while (!q.empty()){
			int v = q.front();
			q.pop();
			if (visited[v]) continue;
			visited[v] = true;
			if (ant[v].mp1) q.push(ant[v].mp1->n); 
			if (ant[v].mp2) q.push(ant[v].mp2->n);
			cout << ant[v].mp1->n << ant[v].mp1->n << endl; 

		}


		for (i = 0; i < n; i++) if (!visited[i]) BotoFe = false;

		(BotoFe)? cout << "All stations are reachable." << endl : cout << "There are stations that are unreachable." << endl;
	}
}

// Fazer as paradinhas que faltam usando a struct