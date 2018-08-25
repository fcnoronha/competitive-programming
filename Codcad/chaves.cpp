// http://www.codcad.com/problem/64

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

int n, cont;
string s;

int main(){
	cin >> n;

	bool res = true;

	fr(i, n+1){
		getline(cin, s);	

		for(int h = 0; h < s.size(); h++){
			if(s[h] == '{') cont ++;
			else if(s[h] == '}') cont --;

			if(cont < 0) res = false;
		}

	}

	if(res == true and cont == 0) cout << "S" << endl;
	else cout << "N" << endl;
}

