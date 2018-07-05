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

int a, n, m, chuva[2001], x[2001], p[2001]], ini, fim;


int main(){
	cin >> a >> n >> m;

	fr(i, n){
		cin >> ini >> fim;

		for(int j = ini, j <= fim, j++){
			chuva[j] ++;
		}
	}

	fr(i, m){
		cin >> x[i] >> p[i];
	}

	
}

