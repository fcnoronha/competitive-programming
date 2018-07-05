//rm -rf .cache/

/*
10⁸ operações levam 1 segundo para rodar no pc

ORDENACAO
sort(vetor, vetor+<tamanho>)
vc pode defirnir um terceiro parametro para o sort, na forma de uma funcao booleana, que ira ter 
uma codição.

BUSCA BINARIA 
particionar a buca por blocos do vetor

int buscaB(int i, int r, int x){
	if (r > 1) return -1;
	int m =( l + r )/2;
	
	if(v[m] == x) return m;
	if(x < v[m]) return buscaB(i, m-1, x);
	else return buscaB(m + 1, r, x);
}
*/



#include<bits/stdc++.h>
using namespace std;

/*
int main(){
	long long int a[100000];
	int x;
	
	cin >> x;
	
	for(int i = 0; i < x; i++){
		cin >> a[i];
	}
	
	sort(a, a+x);
	
	for(int i = 0; i < x; i++){
		cout << a[i] << " ";
	}
}*/

/* 
int n[100000], N;
long k;

int casa(int i, int f, int x) {
	if(i > f) return -1;
	
	int m = (i + f)/2;	
	
	if(n[m] == x) return m;
	if(x < n[m]) return casa(i, m-1, x);
	else return casa(m+1, f, x);
}

int main() {
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> n[i];
	}
	
	cin >> k;
	
	for(int i = 0; i < N; i++){
		int u = k - n[i];

		int res = casa(0, N, u);
		
	
		
		if(res > 0) {
		cout << min(u, res) << " " << max(u, res) << endl;
		break;
		}
	}
		
}
*/

/*

long long int n;



int main(){

	cin >> n;

	
	for(int i = 0; i*i < n; i++){
		if(n == 1 || n == 2){
	        cout << "S" << endl;
	        return 0;
	    }
		else if(n % i == 0){
			cout << "N" << endl;
			return 0;
		}
	}
	cout << "S" << endl;
}

*/

/*
int main(){
	int n;
	long int l, a[1000], ma = 0;
	double d;
	
	cin >> n >> l;
	
	for(int x = 0; x < n; x++){
		cin >> a[x];
	}	
	
	sort(a, a+n);
	long int ant = 0;
	for(int x = 0; x < n; x++){
		
		ma = max(ma, (a[x] - ant));
		ant = a[x];
	}
	
	double dp = max(a[0], l - a[n-1]);
	d = (double)ma/2;
	cout << fixed << setprecision(9) << max(d, dp) << endl;
} */

/* 
int main(){
	int n, m, s = 0, v1, v2 , v3;
	long long int sm[3] = {100000000, 100000000, 10000000}, sum = 0;
	
	cin >> n >> m;
	
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			cin >> s;
			sum += s;
			s = 0;
		}	
		if(sum < sm[0]){
			sm[2] = sm[1];
			sm[1] = sm[0];
			sm[0] = sum;
			v3 = v2;
			v2 = v1;
			v1 = x + 1;
		}
		else if(sum < sm[1]){
			sm[2] = sm[1];
			sm[1] = sum;
			v3 = v2;
			v2 = x + 1;
		
		}
		else if(sum < sm[2]){
			sm[2] = sum;
			v3 = x + 1;
		}
		sum = 0;
		
	}
	
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
} */

/* 
int main(){
	int n, m, p = 0;
	long int pais[100], pot1;

	cin >> n >> m;

	for(int x = 0; x < n; x++){
		pais[x] = 102 - x;
	}
	
	for(int x = 0; x < m; x++){
		pot1 = 1000000000;
		for(int y = 0; y < 3; y++){
			cin >> p;
			pais[p-1] += pot1;
			pot1 = pot1/1000;
		}
	}

    sort(pais, pais+n);
	
	for(int x = n - 1; x >= 0; x--){	
		cout << 103 - (pais[x]%1000) << " ";
	}
	cout << endl;
}
*/

/*
int main()
{
  long int n;
  bool primo = true;

  cin >> n;

  for(int i = 2; i < sqrt(n); i++)
  {
      if(n % i == 0)
      {
          primo = false;
          break;
      }
  }

  if (primo)
      cout << "S";
  else
      cout << "N";
  cout << endl;

}*/


/* TLE
int main(){
	int n, a[1000], max1 = 0, max2 = 0, i;
	long int t, sum = 0;

	cin >> n >> t;

	for(int x = 0; x < n; x++){
		cin >> a[x];
		sum += a[x];
	}

	if(sum <= t){
		cout << n << endl;
	}
	else{
		for(int j = 0; j < n; j++){
			if(sum <= t){
				max2 = max(max2, n-j);
				break;
			}
			for(i = j; i < n; i++){
				max1 += a[i];
				//cout << "I: " << i << " max1:" << max1 << " a:" << a[i] << endl;
	 			if(max1 == t) {
					i++;
				//	cout << "if1:" << i << endl;
					break;
				}
				else if(max1 > t) {
				//	cout << "if2:" << i << endl;
					break;
				}
			}
		//	cout << "max2: " << max2 << " i:" << i << " i-j: " << i-j << endl;
			max2 = max(max2, i-j);
			max1 = 0;
			sum -= a[j];
		}
		cout << max2 << endl;
	}	
}

*/

int n, mx = 0;
long long int a[1000001], k;
bool r[1000001];

int busca(int i, int f, long long int x){
	if(i > f) return -1;
	long int m = (i+f)/2;

	if(a[m] == x) return m;
	else if(a[m] < x) return busca(m+1, f, x);
	else return busca(i, m-1, x); 
}

int main(){
	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		r[i] = true;
	}

	sort(a, a+n);
	mx = n;
	for(int j = 0; j < n; j++){
		if(r[j] != false){
			if(busca(j, n-1, j*k) > 0){
				r[busca(j, n-1, j*k)] = false;
				mx --;
				//cout << "J: " << j << " j*k: " << j*k << busca(j, n-1, j*k) 
			}
		}
	}

	cout << mx << endl;
}























































