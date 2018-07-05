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
typedef vector<long long int> vi;

long long int a[100001],l[100001],r[100001],d[100001], mul[100001];

int n, m, k, oi, uso1, uso2, uso3;

int main(){
	cin >> n >> m >> k;

	frr(i, n){
		cin >> a[i];
	}

	frr(i, m){
		cin >> l[i] >> r[i] >> d[i];

	}

	fr(i, k){
		cin >> uso1 >> uso2;

		for(int u = uso1; u <= uso2; u++){
			mul[u] ++;
		}
	}

	frr(i, m){
		for(int w = l[i]; w <= r[i]; w++){
				a[w] += d[i]*mul[i];
			}
	}

	frr(i, n){
		cout << a[i] << " ";
	}
	cout << endl;
}

