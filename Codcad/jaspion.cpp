// codcad.com/problem/81

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
	fastio;

	int t;
	cin >> t;

	while (t--){

		int m, n;
		cin >> m >> n;

		map<string, string> dic;

		cin.ignore();

		fr(i, m){
			string chave, valor;
			getline(cin, chave);
			getline(cin, valor);

			dic[chave] = valor;
			// dbg(chave);
			// dbg(valor);
		}

		fr(i, n){
			string t;
			getline(cin, t);

			char delim = ' ';
			stringstream ss(t);
    		string item;
    		while (getline(ss, item, delim)) {
    		    
    			// dbg(item);

    			if (dic.find(item) == dic.end()){
    				cout << item << " ";
    			}
    			else{
    				cout << dic[item] << " ";
    			}
    		}
    		cout << endl;
		}
		cout << endl;
	}
}
