// https://codeforces.com/contest/1082/problem/A

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
	int t;
	cin >> t;
	while(t--){
		int n, x, y, d, ans = INT_MAX;
		cin >> n >> x >> y >> d;
		
		int d1, d2, d3, d4;

		if (x>y){

			d1 = x-y; 
			if (d1%d == 0) ans = min(ans, d1/d);

			if ((y-1)%d == 0){
				int aux = ceil((x-1)/(d*1.0));
				aux += (y-1)/d;

				ans = min(ans, aux);
			}

			if ((n-y)%d == 0){
				int aux = ceil((n-x)/(d*1.0));
				aux += (n-y)/d;

				ans = min(ans, aux);
			}

			if (y == 1){
				int aux = ceil(d1/(d*1.0));
				ans = min(ans, aux);
			}
		}

		else if (x<y){

			d1 = y-x;
			if (d1%d == 0) ans = min(ans, d1/d); 

			if ((n-y)%d == 0){
				int aux = ceil((n-x)/(d*1.0));
				aux += (n-y)/d;

				ans = min(ans, aux);
			}

			if ((y-1)%d == 0){
				int aux = ceil((x-1)/(d*1.0));
				aux += (y-1)/d;

				ans = min(ans, aux);
			}

			if (y == n){
				int aux = ceil(d1/(d*1.0));
				ans = min(ans, aux);
			}
		}
		else if (x == y)
			ans = 0;

		if (ans == INT_MAX) ans = -1;

		cout << ans << endl;
	}
}
