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

int n, a[100000], p[100000], sum, mult, total;

int main(){
	cin >> n;

	fr(i, n){
		cin >> a[i] >> p[i];

		if(i == 0){
			sum = a[0];
			mult = p[0];
		}
		else{
			if(p[i] < mult){
				total = total + (mult*sum);
				mult = p[i];
				sum = a[i];
			}
			else{
				sum += a[i];
			}
		}
	}

	total += mult * sum;

	cout << total << endl;
}

