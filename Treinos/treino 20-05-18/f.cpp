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

int R, x, y, soma;

int main(){
	cin >> R;
	fr(i, 3){
		cin >> x >> y;
		frr(i, 10){
			if(x*x+y*y <= R*R*i*i){
				soma += 10-(i-1);
				break;
			}
		}
	}
	cout << soma << endl;
}

