/*   ARRAYS
Um vetor ´e definido como:
   int v[5];
   em que V tera cinco posiçoes que vao de 0 ate 4 (v[0], v[1], v[2], v[3], v[4])

elas podem ser acessadas assim:
   int v[0] = 1;
   em que a primeira posiç~ao do vetor V recebera 1

para adicionar varias posiçoes usasse:
   v[5] = {3,23,5,1,9};

o tamanho do vetor vai depender da restriç~ao do problema, sendo que os dados serao 
inseridos atravez de um for()
*/

/*  FUNCOES
	<tipo_de_retorno> <nome> (<argumentos>)
		<codigo>

	
	double media(double x, double y, double z) {
		double media = (x+y+z)/3;
		return media;  
	}

*/    

#include <bits/stdc++.h>
using namespace std;

/* guerra
int main() {
	int n, a[100000], y, j=0, soma = 0, meio = 0;

	cin >> n;

	for(int x = 0; x < n; x++) {
		cin >> a[x];
		soma = soma + a[x];
	}

	for(y = 0; y < n; y++) {
		j++;
		meio = meio + a[y];
		if (meio == soma/2) {
			break;
		}
	}

	cout << j << endl;

} 
*/

/*vestibular
int main() {
	int n, r = 0;
	char gabarito[80], res[80];
	cin >> n;

	for (int x; x < n; x++) {
		cin >> gabarito[x];
	}

	for (int x; x < n; x++) {
		cin >> res[x];
		if (res[x] == gabarito[x]) {
			r ++;
		}
	}

	cout << r << endl;
}
*/

/* way too long
int main() {
	int n;
	string palavra[100], res[100];
	cin >> n;

	for(int x = 0; x < n; x++) {
		cin >> palavra[x];
	}

	for(int x = 0; x < n; x++) {
		int y = palavra[x].length();
		if(y <= 10) {
			cout << palavra[x] << endl;
		}
		else {
			cout << palavra[x][0] << y - 2 << palavra[x][y-1] << endl;
		}
	}
}
*/

/* arrays
int main() {
	int a, b, k, m;

	cin >> a >> b;
	cin >> k >> m;

	int na[100000];
	for (int x = 0; x < a; x++){
		cin >> na[x];
	}	

	int nb[100000];
	for (int y = 0; y < b; y++){
		cin >> nb[y];
	}

	if(na[k-1] < nb[b-m]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
*/

/* pebbles, ARRUMAR TLE
int main() { 
	int n, k, w[10000], days = 0;
	cin >> n >> k;

	for(int x = 0; x < n; x++) {
		cin >> w[x];
		days += w[x]/k;
		if(w[x]%k > 0) days ++;
	}

	cout << (days/2) + (days%2) << endl;
}
*/ 

/*
UHAUHAUHAH
int main() {
	string pa;
	char vogais[50];
	int n = 0;
	cin >> pa;

	for(int x = 0; x <  pa.length(); x++) {
		if(pa[x] == 'a' || pa[x] == 'e' || pa[x] == 'i' || pa[x] == 'o' || pa[x] == 'u') {
			vogais[n] = pa[x];
			n++;
		}
	}

	for(int y = 0; y < n; y++) {
		if(vogais[y] != vogais[n - y - 1]) {
			cout << "N" << endl;
			break;
		}
		else if(y == (n - 1)) {
			cout << "S" << endl;
		}

	}
}
*/

/* ver pq esta dando erro FRACTION
int main() {
	int n, a, b, w = 0,h = 0;
	cin >> n;

	for(int x = 0; x < n; x++) {
		a = x;
		b = n - x;
		if(a > 1 && b > 1 ) {
			for(int y = 0; y < n; y++){
				if(a%y != 0 && b%y != 0 && a > w){
					w = a;
					h = b;
				}
			}
		}
	}

	cout << min(w,h) << " " << max(w,h) << endl;

}
*/



   










