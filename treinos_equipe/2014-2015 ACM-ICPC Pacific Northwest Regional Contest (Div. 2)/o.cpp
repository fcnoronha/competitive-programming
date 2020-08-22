#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 201;

int memo[N], n;

vector<pair<double, double>> arr;

int dp(int i){
    if(i == n) return 0;
    int& pdm = memo[i];
    if(pdm != -1) return pdm;
    pdm = 1;
    for(int k = i + 1; k < n; k++){
        if(!(arr[k].ff > arr[i].ff && arr[k].ss < arr[i].ss)) continue;
        pdm = max(pdm, 1 + dp(k));
    }
    return pdm;
}

int main(){
    rvr(t);
    while(t--){
        scanf("%d", &n);
        arr.clear();
        fr(i, n){
            memo[i] = -1;
            double aa, bb; scanf("%lf%lf", &aa, &bb);
            arr.pb(mp(aa, bb));
        }
        int ans = -1;
        fr(i, n) ans = max(ans, dp(i));
        printf("%d\n", ans);
    }

}
