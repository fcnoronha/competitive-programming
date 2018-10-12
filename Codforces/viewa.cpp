// http://codeforces.com/problemset/problem/257/C
// Achando semi-circulo minimo de visao

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define EPS 1e-9
#define f first
#define s second

const float PI = acos(-1);	

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	int n;
	cin >> n;

	float p[n+2], x, y;
	fr(i, n){
		cin >> x >> y;
		p[i] = atan2(y, x);
		if (p[i] < -EPS) p[i] += 2*PI;
	}

	sort(p, p+n);
	float angle = p[n-1] - p[0];
	fr(i, n-1){
		float aux = 2*PI - (p[i+1] - p[i]);
		angle = min(angle, aux);
	}

	cout << setprecision(10) << fixed << angle*180/PI << endl;
}
