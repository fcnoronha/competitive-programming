#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n, m, a[1000000];
ll sum;

int main(){
	cin >> n >> m;

	fr(i, n){
		cin >> a[i];
	}

	fr(i, n){
		if(i == 0) a[0] = min(a[0], m - a[0]);
		else if(m - a[i] < a[i] and m - a[i] >= a[i - 1]) a[i] = m - a[i];
		else if(a[i] < a[i-1] and m - a[i] >= a[i -1]) a[i] = m - a[i];
		else if(a[i] < a[i-1] and m - a[i] < a[i-1]){
			cout << "-1" << endl;
			return 0;
		}
	}

	fr(i, n){
		sum += a[i];
	}

	cout << sum << endl;
}

