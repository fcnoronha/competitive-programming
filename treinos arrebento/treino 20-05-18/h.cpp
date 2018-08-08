#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define grtp greater<pair<int,int>>

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()

#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
#define olar() cout << "olaarr" << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;

int xo, yo, xd, yd, d;
char c;

queue<string> fila;

string make_move(int x){
	char lol;
	string num="",aux="A ";
	while(x>0){
		lol='0'+x%10;
		num=lol+num;
		x=x/10;
	}
	aux+=num;
	return aux;
}

int main(){

	cin >> xo >> yo >> c >> xd >> yd;

	if(c == 'E') d = 0;
	else if (c == 'N') d = 3;
	else if(c == 'O') d = 2;
	else d = 1;

	int  x = d, y= d;

	if(xd > xo) x = 0;
	else if(xd < xo) x = 2;

	if(yd > yo) y = 3;
	else if(yd < yo) y = 1;

	int dy=abs(yd-yo);
	int dx=abs(xd-xo);

	fr(i, 4){

		if(d==x && dx!=0){
			fila.push( make_move(dx) );
			xo=xd;
		}

		if(d==y && dy!=0){
			fila.push( make_move(dy) );
			yo=yd;
		}

		if(xo==xd && yo==yd)	break;
		
		fila.push("D");
		d=(d+1)%4;
	}

	cout << fila.size() << endl;
	while(!fila.empty()){
		cout << fila.front() << endl;
		fila.pop();
	}


}


