// https://codeforces.com/contest/1093/problem/B

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
	fastio

	int t;
	cin >> t;
	while (t--){

		string s;
		cin >> s;
		int n = s.length();

		bool nao = true;
		frr(i, n-1)
			if (s[i] != s[i-1]) 
				nao = false;

		if (nao) cout << "-1" << endl;

		else {

			bool pal = false;
			fr(i, n)
				if (s[i] != s[n-1-i])
					pal = true;

			if (pal) cout << s << endl;

			else {
				bool troca = true;
				for (int i = 1; i < n && troca; i++)
					if (s[i] != s[i-1]){
						troca = false;
						swap(s[i], s[i-1]);
					} 

				cout << s << endl;
			}

		}
		
	}
}
