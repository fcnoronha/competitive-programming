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
	ll n, m, x1,x2,y1,y2;

	cin >> n >> m >> y1 >> x1 >> y2 >> x2;

	ll he = y2-y1;
	ll ans = (m%2 == 1)*(n-he);
	ans += ((x1-1)%2 == 1)*he;
	ans += ((m-x2)%2 == 1)*he;

	cout << ans << endl;
}	
