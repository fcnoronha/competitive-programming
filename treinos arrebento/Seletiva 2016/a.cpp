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
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
	double h, w;
	double x, y, minx, mxx, miny, mxy;
	double xs[4], ys[4];

	mxx = mxy = 0.0;
	minx = miny = 100000.0;

	cin >> h >> w;
	fr (i, 4){
		cin >> x >> y;
		xs[i] = x;
		ys[i] = y;
		minx = min(minx, x);
		mxx = max(mxx, x);
		miny = min(miny, y);
		mxy = max(mxy, y);
	}

	double dx, dy;

	dx = mxx - minx;
	dy = mxy - miny;

	double r = w/dx;

	x = (minx)/(r-1.0);
	y = (miny)/(r-1.0);
	x *= r;
	y *= r;

	if (ys[0] == ys[1]){
		if (xs[0] > xs[3]){
			y = mxx/(1+r)*r;
			dbg(1);
		}
		else{
			x = mxx/(1+r)*r;
			y = mxy/(1+r)*r;
			dbg(2);
		} 
	}
	else if (ys[0] == ys[3]){
		if (xs[3] < xs[0]){
			x = miny/(1+r)*r;
			y = minx/(r-1)*r;
			dbg(3);
		} 
		else{
			x = miny/(r-1)*r;
			y = minx/(1+r)*r;
			dbg(4);
		}
	}
	else if (ys[2] == ys[3]){
		if (ys[2] > ys[1]){
			x = mxx/(1+r)*r;
			dbg(5);
		} 
		else{
			x = minx/(r-1)*r;
			dbg(6);
		}
	}
	else if (ys[1] == ys[2]){
		if (ys[1] > ys[0]){
			y = minx/(r-1)*r;
			x = miny/(r-1)*r;
			dbg(7);
		} 
		else{
			x = miny/(r-1)*r;
			dbg(8);
		} 
	}

	cout << fixed << setprecision(r) << x << " " << y << endl;
}