// http://codeforces.com/contest/1062/problem/A

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

int n, a[106], ans, aux;

int main(){
	cin >> n;

	a[0] = 0;
	a[n+1] = 1001;

	frr(i, n){
		cin >> a[i];
	}
	
	fr(i, n+1){
		if (i <= n-1 && a[i] == a[i+2]-2)
			aux++;
		else if (aux > 0){
			ans = max(ans, aux);
			aux = 0;
		}
	}

	cout << ans	 << endl;
}
