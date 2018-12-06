// https://codeforces.com/contest/1088/problem/C

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

int main(){
	ll n;
	cin >> n;

	ll a[n+2];
	fr(i, n)
		cin >> a[i];
	
	cout << n+1 << endl;
	ll ac = 0;
	for (int i = n-1; i>= 0; i--){
		ll aux = i + n - (a[i] + ac)%n;
		cout << 1 << " " << i+1 << " " << aux << endl;
		ac += aux;
	}

	cout << 2 << " " << n << " " << n << endl;
}
