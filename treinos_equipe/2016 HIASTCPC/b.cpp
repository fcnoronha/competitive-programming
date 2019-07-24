#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll mod = 1000000007;

typedef vector< vector<ll> > matrix;

matrix operator*(matrix& a, matrix& b){

	matrix aux; aux.resize(3);

	for (int i = 0; i < 3; i++)
		aux[i].resize(3);

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			aux[i][j]=0ll;
			for (int k = 0; k < 3; k++)
				aux[i][j] = (aux[i][j] + (a[i][k] * b[k][j]))%mod;
		}
	}
	return aux;
}

matrix id(int x){
	matrix v;
	v.resize(3);
	for (int i = 0; i < 3; i++){
		v[i].resize(3);
		v[i][i] = 1ll;
	}
	return v;
}

void exp(matrix& a, ll x){
	matrix ans = id(a.size());
	while (x > 0){
		if(x%2 == 1)
			ans=ans*a;
		a=a*a;
		x=x/2;
	}

	a = ans;
}

int main(){
	fastio

    int t;
    cin >> t;

    while (t--) {

        ll n;
        cin >> n;

        if (n == 1) {
            p("3");
            continue;
        }

        n--;
        matrix aux = matrix({{1,2,3},{4,5,6},{7,8,9}});
        exp(aux, n);

        ll ans = 0ll;
        fr(i, 3)
            fr(j, 3)
                ans = (ans+aux[i][j])%mod;

        p(ans);
    }
}
