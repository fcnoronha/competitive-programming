#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

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
const int N = 1e5 + 1;
const ll mod = 1e9 + 7;

string s;
int n;
ll memo[N];

ll dp(int i){
    if(i == n) return 1;
    if(memo[i] != -1) return memo[i];
    memo[i] = 0;
    if((s[i] == 'N' || s[i] == 'S') && i != n -1 && (s[i+1] == 'E' || s[i+1] == 'W')){
        memo[i] = dp(i+2);
    }
    memo[i] = memo[i] + dp(i+1);
    memo[i] %= mod;
    return memo[i];
}

int main(){
    fastio;
    ms(memo, -1);
    #ifdef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> s;
    n = s.size();
    cout << dp(0) << endl;

}