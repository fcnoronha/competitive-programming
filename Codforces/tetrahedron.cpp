// http://codeforces.com/problemset/problem/166/E

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll mod = 1000000007;

typedef vector< vector<ll> > matrix;

matrix operator*(matrix& a, matrix& b){

	int a1=4; int a2=4;
	int b1=4; int b2=4;

	matrix aux = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	
	for(int i=0;i<a1;i++){
		for(int j=0;j<b2;j++){
			aux[i][j]=0ll;
			for(int k=0;k<a2;k++){
				aux[i][j]+=a[i][k] * b[k][j];
				aux[i][j]=aux[i][j]%mod;
			}
		}
	}
	return aux;
}

matrix id(){
	matrix v = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

	for(int i=0;i<4;i++){
		v[i][i]=1ll;
	}
	return v;
}

void exp(matrix& a, ll x){
	matrix ans = id();
	while(x>0){
		if(x%2==1)
			ans=ans*a;
		a=a*a;
		x=x/2;
	}
	cout << ans[3][3] << endl;

}

int main(){
	ll x;
	cin >> x;

	matrix m = {{0,1,1,1}, {1,0,1,1},
				   	  {1,1,0,1}, {1,1,1,0}};

	exp(m, x);

}