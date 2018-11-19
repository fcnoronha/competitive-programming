// http://codeforces.com/contest/1079/problem/B

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

int main(){
	string s;
	cin >> s;
	int n = s.length();

	if (n <= 20){
		cout << 1 << " " << n << endl << s << endl;
		return 0;
	}

	int d = 2;
	while ((n % d > d || n / d > 20) && d < 5)
		d++;

	int col = n/d; 
	
	int astC = n - (n/d)*d;
	if (astC > 0) {
		if (col < 20) col++;
		else {
			d++;
			col = n/d; 
		
			astC = n - (n/d)*d;
			if (astC > 0) col++;
		}
	}


	cout << d << " " << col << endl;


	astC = (col*d) - n;

	int cu = 0;
	for (int i = 0; i < d; i++){
		int j = 0;
		if (astC > 0){
			cout << "*";
			astC--;
			j ++;
		}
		for (j; j < col; j++)
			cout << s[cu++];	
		cout << endl;
	}
}
