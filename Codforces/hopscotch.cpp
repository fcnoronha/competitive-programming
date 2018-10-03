// http://codeforces.com/problemset/problem/141/B?locale=en

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int fun(){
	int a, x, y, nc = 1, escl = 0, t;

	cin >> a >> x >> y;

	if (y == 0 || y == a) return -1;
	if (a > y && abs(x) < (a/2.0)) return nc;
	if (a > y && abs(x) >= (a/2.0)) return -1;
	y -= a;

	escl = floor(y/(2*a));
	// nc++;
	nc += 3*escl;
	y = floor(y % (2*a));

	if (y == 0 || y == a) return -1;

	if (y < a){
		if (abs(x) >= a/2.0) return -1;
		return (nc + 1);
	}
	if (y > a){
		nc++;
		if (abs(x) == 0 || abs(x) >= a) return -1;
		if (x < 0) return (nc+1);
		if (x > 0) return (nc+2);
	}
	return -1;
}

int main(){
	printf("%d\n", fun());
	return 0;
}
