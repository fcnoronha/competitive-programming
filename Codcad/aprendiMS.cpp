// codcad.com/problem/84

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

void intercala(int v[], int ini, int meio, int fim){
	
	int aux[fim-ini];
	int i = ini, j = meio, k = 0;

	while (i < meio && j < fim){
		if (v[i] > v[j])
			aux[k++] = v[i++];
		else 
			aux[k++] = v[j++];
	}

	while (i < meio)
		aux[k++] = v[i++];

	while (j < fim)
		aux[k++] = v[j++];

	for (int i = ini, k = 0; i < fim; i++, k++)
		v[i] = aux[k];

}

void mergeS(int v[], int ini, int fim)
{
	if (ini < fim-1){
		int meio = (fim + ini)/2;
		mergeS(v, ini, meio);
		mergeS(v, meio, fim);
		intercala(v, ini, meio, fim);
	}
}

int main(){
	fastio 

	int n;
	cin >> n;

	int v[n];
	fr(i, n) cin >> v[i];

	mergeS(v, 0, n);

	fr(i, n){
		cout << v[i];
		if (i < n-1) cout << " ";
		else cout << endl;
	}
}