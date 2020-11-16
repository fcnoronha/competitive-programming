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
const int N = 1e6 + 1;

double memo[N], pref[N];

int n, a, b;

double vaca;


int main(){
    scanf("%d%d%d", &n, &a, &b);
    pref[0] = 0;
    memo[0] = 0;
    vaca = 1.0/(double)(b - a + 1);
    frr(i, n){
        if(a == 0){
            memo[i] = (1 + vaca*(pref[max(i-1, 0)] - pref[max(i-b-1, 0)]))/(1.0 - vaca);
        }
        else{
            memo[i] = 1 + vaca*(pref[max(i-a, 0)] - pref[max(i-b-1, 0)]);
        }
        pref[i] = pref[i-1]+memo[i];
        //printf("memo[%d] = %f\n", i, memo[i]);
    }
    printf("%.5f\n", memo[n]);
}
