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

int v[100100];
int pd[100100];
int valores[100100];
int solve(int i){
    //if(i >=n) return 0;
    

}


signed main() {
    fastio;
	int n,c,t1,t2;
    cin >> n >> c >> t1 >> t2;
    for(int i = 0; i<n; i++) cin >> v[i];
    int ans = INF;
    for(int i = 0; i<n; i++){
        int t = 0;
        for(int j = i; j<n; j++){
            valores[t++] = v[j];
        }
        int falta = c - v[n-1];
        for(int j = 0; j<i; j++){
            valores[t++] = v[n-1] + falta + v[j];
        }
        for(int j = 0; j<n; j++) pd[i] = INF;
        pd[n] = 0;
        for(int j = n-1; j>=0; j--){
            int x = valores[j];
            int prox1 = upper_bound(valores+j, valores+n, x + t1) - valores;
            int prox2 = upper_bound(valores+j, valores+n, x+t2) - valores;
            
            pd[j] = min(t1 + pd[prox1], t2 + pd[prox2]);
        }
        ans = min(ans, pd[0]);

    }
    cout << ans << endl;
	
}