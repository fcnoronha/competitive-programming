#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
// codeforces.com/contest/1076/problem/C

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	int t;
	cin >> t;
	fr(i, t){

		double a = 0.0,b = 0.0,d;
		cin >> d;

		if (d == 0){
			cout << "Y " << fixed << setprecision(9) << a << " " << b << endl;
			continue;
		}

		if (d < 4){
			cout << "N" << endl;
			continue;
		}

		double delta = pow(d, 2) - 4*d;
		delta = sqrt(delta);

		b = d - delta;
		b /= 2.0;

		a = d - b;

		cout << "Y	 " << fixed << setprecision(9) << a << " " << b << endl;

	}
}
