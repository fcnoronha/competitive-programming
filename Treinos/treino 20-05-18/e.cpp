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

int main(){
	int tempos[100000];
	int N;
	cin >> N;
	fr(i, N){
		cin >> tempos[i];
	}
	sort(tempos,tempos+N);
	if(N == 1){
		cout << tempos[0] << endl;
		return 0;
	}
	else if(N == 2){
		cout << tempos[1] << endl;
		return 0;
	}
	else if(N == 3){
		cout << tempos[0] + tempos[1] + tempos[2] << endl;
		return 0;
	}
	int total = (N/2)*(tempos[0]+tempos[1])-tempos[0];
	for(int i = N-1; i > 1; i -= 2){
		total += tempos[i] + tempos[1];
	}
	if(N%2 == 1){
		total -= tempos[0];
	}
	cout << total << endl;
}

