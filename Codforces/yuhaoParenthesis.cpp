// codeforces.com/contest/1097/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
	fastio

	int n;
	cin >> n;

	vi cls(500009, 0);
	vi opn(500009, 0);

	int ans = 0;
	fr(i, n){
		string aux;
		cin >> aux;

		int cnto = 0, cntc = 0;
		stack<char> porra;
		fr(j, aux.size()){

			if (porra.empty())
				porra.push(aux[j]);

			else if (porra.top() == '(' && aux[j] == ')') porra.pop();
			else porra.push(aux[j]);
		}

		while (!porra.empty()){
			char caralho = porra.top();
			porra.pop();

			if (caralho == '(') cnto++;
			else cntc++;
		}

		if (cntc > 0 && cnto == 0){

			if (opn[cntc] > 0){
				opn[cntc]--;
				ans++;
			}

			else
				cls[cntc]++;

		}

		else if (cnto > 0 && cntc == 0){

			if (cls[cnto] > 0){
				cls[cnto]--;
				ans++;
			}

			else
				opn[cnto]++;
		}

		else if (cntc == 0 && cnto == 0){

			if (cls[0] > 0){
				ans++;
				cls[0]--;
			}

			else
				cls[0]++;

		}
	}

	cout << ans << endl;
}
