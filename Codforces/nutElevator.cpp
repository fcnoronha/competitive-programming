// codeforces.com/contest/1084/problem/A

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

int a[102];

int main(){
	int n;
	cin >> n;
	fr(i, n)
		cin >> a[i];

	int ans = INT_MAX;
	fr(x, n){ // x-floor
		int aux = 0;
		fr(j, n){ // Actual
			int aux2 = abs(j-x) + j + x;
			aux2 += x + j + abs(j-x);
			aux2 *= a[j];
			aux += aux2;
		}

		ans = min(ans, aux);
	}

	cout << ans << endl;
}
	