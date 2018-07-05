#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define grtp greater<pair<int,int>>

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()

#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
#define olar() cout << "olaarr" << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;

int n;

int main(){
	cin >> n;
	if(n == 3){
		cout << "--+" << endl;
		return 0;
	}
	else if((n*(n+1))%4 != 0){
		cout << "-1" << endl;
		return 0;
	}
	
	fr(i, n/2	){
		if(i%2 == 0){
			cout << "-";
		}
		else{
			cout << "+";
		}
	}

	for(int i = n/2; i < n - n%2; i++){
		if(i%2 == 0){
			cout << "+";
		}
		else{
			cout << "-";
		}
	}
	if(n%4 != 0){
		cout << "+";
	}

	cout << endl;	
	
}

