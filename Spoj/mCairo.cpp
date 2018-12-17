// https://br.spoj.com/problems/MCAIRO/

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

#define MAXN 1009
int bit[MAXN][MAXN];

int sum(int x, int y){
		
	int ans = 0;
	
	for (int i = x; i > 0; i -= i&-i)
		for (int j = y; j > 0; j -= j&-j)
			ans = max(bit[i][j], ans);

	return ans;
}

void update(int x, int y, int v){
		
	for (int i = x; i < MAXN; i += i&-i)
		for (int j = y; j < MAXN; j += j&-j)
			bit[i][j] = max(bit[i][j], v);

	return;
}

int main(){	
	fastio

	int t;
	cin >> t;
	while(t--){

		int n, ans = 0;
		cin >> n;

		fr(i, 1002)
			fr(j, 1002)
				bit[i][j] = 0;

		frr(i, n){
			int a, b;
			cin >> a >> b;

			int aux = sum(a, b) + 1;
			ans = max(ans, aux);

			update(a, b, aux);
		}

		cout << ans << endl;

	}
}
