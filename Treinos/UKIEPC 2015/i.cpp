#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

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
typedef long double ld;

char hard[] = {'b', 'c', 'd', 'g', 'k', 'n', 'p', 't'};

bool ish(char c){

	fr(i, 8)
		if (c == hard[i])
			return true;

	return false;
}

int main(){

	vector<string> ans;

	char c = 0;
	string aux = "";
	scanf(" ");
	while (c != '\n'){

		while (scanf("%c", &c) != EOF && !isspace(c))
			aux += c;

		bool mn = false;
		if (aux[0] >= 'A' && aux[0] <= 'Z')
			aux[0] = tolower(aux[0]), mn = true;

		int dist = 30;
		char pu;
		fr(i, 8)
			if (abs(hard[i]-aux[0]) < dist)
				dist = abs(hard[i]-aux[0]), pu = hard[i];

		aux[0] = pu;

		string auxx = "";
		auxx += aux[0];
		bool muda = false;

		for (int j = 1; j < aux.size(); j++){

			if (aux[j] == '-'){
				muda = 1;
				continue;
			}

			if (muda && ish(aux[j])){
			 	auxx += aux[0];
				continue;
			}

			if (aux[j] != '-')
				auxx += aux[j];
		}

		aux = auxx;

		// Third cond
		char oi = aux.back();

		if (ish(oi)){

			int dist = 30;
			char pu;
			for (auto cp : {'a', 'o', 'u'})
				if (abs(cp - oi) < dist)
					pu = cp, dist = abs(cp-oi);

			aux += pu;
			aux += "h";
		}

		if (mn)
			aux[0] = toupper(aux[0]);

		ans.pb(aux);
		aux = "";
	}

	for (auto u : ans)
		cout << u << " ";
	cout << endl;

}
