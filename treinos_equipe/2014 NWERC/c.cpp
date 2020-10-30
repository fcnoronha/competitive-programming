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
#define tsts(t) rvr(t); while(t--)

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
const int N = 2e3 + 1;

int memo[N][22];
int n, d;
int p[N];

int rnd(int p){
    if(p%10 >= 5){
        return p + 10 - (p%10);
    }
    return p - (p%10);
}

int suf[N];

int dp(int i, int lf){
    if(i == n) return 0;
    int& pdm = memo[i][lf];
    if(pdm != -1) return pdm;
    if(!lf){
        pdm = suf[i];
        pdm = rnd(pdm);
        return pdm;
    }
    pdm = rnd(p[i]) + dp(i+1, lf-1);
    int plc = p[i];
    for(int j = i + 1; j < n; j++){
        plc += p[j];
        pdm = min(pdm, rnd(plc) + dp(j+1, lf-1));
    }
    return pdm;
}

int main(){
    scanf("%d%d", &n, &d);
    ms(memo, -1);
    fr(i, n){
        scanf("%d", &p[i]);
    }
    fr(ii, n){
        int i = n - 1 - ii;
        suf[i] = (i==(n-1)?p[i]:suf[i+1]+p[i]); 
    }
    printf("%d\n", dp(0, d));
}