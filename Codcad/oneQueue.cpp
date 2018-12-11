// http://www.codcad.com/problem/133

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

	if (n == 0){
		cout << "N" << endl;
		return 0;
	}

	while(n > 0){

		if ((n&-n) > 1){
			cout << "N" << endl;
			return 0;
		}
    	n -= n&-n;
    	n >>= 1;
  	}

  	cout << "S" << endl;
}
