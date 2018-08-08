#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define otp(x) cout << x << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

const double epsilon = 1e-6;

double processa(int mask, vi& vetor){
	
	int len = vetor.size();
	double sum = 0;
	
	fr(i,len){
		if((1<<i)&mask)
			sum+=log2(vetor[i]);
	}

	return sum;
}

int conta(int mask, int len){

	int sum=0;

	fr(i,len)
		if(mask&(1<<i))
			sum++;

	return sum;

}

int main(){
	
	int n,m;

	vi fnorm,snorm;
	vector<pair<double,int>> flog,slog;

	cin >> n >> m;

	fr(i,n){
		int aux; cin >> aux;
		fnorm.pb(aux);
	}

	fr(i,m){
		int aux; cin >> aux;
		snorm.pb(aux);
	}

	fr(i,(1<<n)){
		if(!i)	continue;
		double sum = processa(i,fnorm);
		flog.pb({sum,i});
	}

	fr(i,(1<<m)){
		if(!i)	continue;
		double sum = processa(i,snorm);
		slog.pb({sum,i});
	}

	sort(all(flog));
	sort(all(slog));

	int ini=0,end=0;
	int l1,l2;
	l1 = flog.size();
	l2 = slog.size();

	fr(i,l1){

		auto it = lower_bound(all(slog),mp(flog[i].fst-epsilon,0));
		pair<double,int> aux = *it;
		if(abs(aux.fst-))

	}	



}