// https://codeforces.com/contest/1092/problem/A

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
	fastio
	
	int t;
	cin >> t;

	while (t--){

		int n, k;
		cin >> n >> k;

		vector<char> v;
		int porra = 0;
		fr(i, n){
			if (porra < k)
				v.pb(97 + porra++);
			else 
				porra = 0, v.pb(97 + porra++);
		}

		fr(i, n) cout << v[i];
		cout << endl;
	}	
}

