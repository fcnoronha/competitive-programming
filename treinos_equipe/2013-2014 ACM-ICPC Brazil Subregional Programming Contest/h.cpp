#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define all(x) x.begin(),x.end()
#define int long long int
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
const int INF = 0x3f3f3f3f;


const int mod = 1e6;
#define REP(i, n) for(int i = 0; i < (n); i++)
struct Matrix {
	long long a[2][2];
	Matrix() {
		REP(i, 2) {
			REP(j, 2) {
				a[i][j] = 0;
			}
		}
	}
	Matrix operator *(Matrix other) {
		Matrix product = Matrix();
		REP(i, 2) {
			REP(j, 2) {
				REP(k, 2) {
					product.a[i][k] += a[i][j] * other.a[j][k];
					product.a[i][k] %= mod;
				}
			}
		}
		return product;
	}
};
Matrix expo_power(Matrix a, long long n) {
	Matrix res = Matrix();
	res.a[0][0] = res.a[1][1] = 1;
	while(n) {
		if(n % 2) {
			res = res * a;
		}
		n /= 2;
		a = a * a;
	}
	return res;
}
signed main() {
    fastio;
	int n, k,l;
    cin >> n >> k >> l; 
	Matrix single = Matrix();
    k %= (ll)1e6;
    l %= (ll)1e6;
	single.a[0][0] = k;
	single.a[0][1] = l;
	single.a[1][0] = 1;
	single.a[1][1] = 0;

    int expo = n/5;

	Matrix total = expo_power(single, expo);
    int ans = total.a[0][0];
    int dg = 0;
    int copiaAns = ans;
    vector<int> digito;
    if(ans == 0){
        for(int i = 0; i<6; i++) cout << 0;
        cout << endl;
        return 0;
    }
    while(copiaAns){
        digito.push_back(copiaAns%10);
        dg++;
        copiaAns /= 10; 
    }
    reverse(all(digito));
    for(int i = 0; i<6-dg; i++) cout <<0;
    for(int i = 0; i<dg; i++){
        cout << digito[i];
    }
    cout << endl;
    
    

	
}