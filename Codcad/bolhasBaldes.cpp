// http://www.codcad.com/problem/157

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

#define MAXN 100000
int bit[100009];

int query(int i){
	int sum = 0;
    for (; i > 0; i -= i&-i) 
    	sum += bit[i];
    return sum;
}

void update(int x, int i){
	for (; i <= MAXN; i += i&-i)
		bit[i] += x;
}

int main(){
	fastio

	int n;
	while(cin >> n && n != 0){

		int a[n+3];
		frr(i, n){
			bit[i] = 0;
			cin >> a[i];
		}

		ll ans = 0;
		for (int i = n; i > 0; i--){
			ans += query(a[i] - 1);
				update(1, a[i]);
		}

		if (ans%2 != 0) cout << "Marcelo" << endl;
		else cout << "Carlos" << endl;
	}
}
