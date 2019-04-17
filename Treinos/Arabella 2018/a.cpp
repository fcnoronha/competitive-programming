//https://codeforces.com/gym/101972

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;

int clk;

void print(int a, int b){

	if(!a || !b)	return;

	if(!clk)	clk++;
	else		cout << " + ";

	cout << a << " x " << b;

}

void go(){
	vi x,y;
	int a,b;
	clk=0;
	cin >> a >> b;
	do{
		x.pb(a%10);
		a/=10;
	}while(a!=0);
	do{
		y.pb(b%10);
		b/=10;
	}while(b!=0);
	for(int i=0;i<x.size();i++)
		for(int j=0;j<y.size();j++){
			if(a*b<0)	print( -1*int(x[i]*pow(10,i)),int(y[j]*pow(10,j)) );
			else		print( int(x[i]*pow(10,i)),int(y[j]*pow(10,j)) );
		}
	gnl;
}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	go();
	
}