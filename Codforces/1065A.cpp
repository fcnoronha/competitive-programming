// http://codeforces.com/contest/1065/problem/A

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

ll t, s, a, b, c;

int main(){
	cin >> t;
	while(t--){
		cin >> s >> a >> b >> c;
		ll aux = s/c;
		ll aux2 = aux;
		aux = aux/a;
		aux *= b;
		cout << aux+aux2 << endl;
	}
}
