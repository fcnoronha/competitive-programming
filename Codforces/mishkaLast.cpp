// https://codeforces.com/contest/1093/problem/C

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll b[300009], a[300009];

int main(){
	fastio

	ll n;
	cin >> n;
	frr(i, n/2)
		cin >> b[i];

	a[n+1] = LLONG_MAX;
	a[0] = 0ll;

	frr(i, n/2){

		ll a2 = min(a[n-i+2], b[i]);
		ll a1 = b[i] - a2;

		ll a3;

		if (a1 < a[i-1]){
			a3 = a[i-1] - a1;
			a1 += a3;
			a2 -= a3;
		}

		a[i] = a1;
		a[n-i+1] = a2;
	}

	frr(i, n)
		cout << a[i] << " ";

	cout << endl;
}
