/* FUNCAO REURSIVA	
funcao que ela mesma em seu escopo

funcao fibonacci
int f(int n){
	if (n==0 || n==1) return 1;
	return f(n-2) + f(n-2);
}

MATRIZES
*/


#include <bits/stdc++.h>
using namespace std;

/* rain
int main() {
	int c[200][200], n;

	cin >> n;

	for(int i = 0; i < 2*n; i++){
			for(int j = 0; j < n; j++){
				cin >> c[i][j];
			}
	}

	for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << c[i][j] + c[i+n][j] << " ";
			}
		cout << endl;
	}
}
*/

/* FAZER DPS PQ TA ERRADO (MAGIC SQUARE)
int main() {
	int n, c[10][10], li[10], co[10], d1 = 0, d2 = 0, l, col;

	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> c[i][j];
			li = li + c
			co = co + c
		}
	}

	if co/n == li/n

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			li[i] = li[i] + c[i][j];
		}
		if((i > 0) and (li[i] != li[i-1])){
			l=0;
			break;
		}
		else {
			l=li[i];
						
		}
	}

	for(int j = 0; j < n; j++){
		co[j] = 0;
		for(int i = 0; i < n; i++){
			co[j] = co[j] + c[i][j];
		}	
		if((j > 0) and (co[j] != co[j-1])){
			col = 0;
			break;
		}
		else {

			col = co[j];
			
			
		}
	}

	for(int i = 0; i < n; i++){
		d1 = d1 + c[i][i];
	}


	for(int i = 0; i < n; i++){
		d2 = d2 + c[i][n-1-i];
	}

	

	if(l == col and col == d1 and d1 == d2){
		cout << l << endl;
	}
	else {
		cout << "-1" << endl;
	}
}
*/

/*   3n+1
int main(){
	int n, cont=0;

	cin >> n;

	while(n != 1){
		if(n%2 == 0){
			n = n/2;
			cont++;
	    }
		else {
			n = (3*n)+1;
			cont++;
		
		}	
	}

	cout << cont << endl;
	
}
*/

int main(){
	int n, x[1000][1000], s = 0, sl[1000], sc[1000];

	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> x[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sl[i] = sl[i] + x[i][j]; 
		}
	}

	for(int j = 0; j < n; j++) {
		for(int i = 0; i < n; i++) {
			sc[j] = sc[j] + x[i][j]; 
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int y = 0;
			y = sc[j] + sl[i] - 2*(x[i][j]);
			if(y > s){
				s = y;
			}
		}
	}

	cout << s << endl;
}