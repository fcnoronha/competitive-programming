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
const int N = 1e5 + 1;

pii ans[N];
ll memo[N];

ll dp(int i){
    if(memo[i] != -1) return memo[i];
    ll& pdm = memo[i];
    pdm = 0;
    if(ans[i].ff != i){
        pdm = (ll)(ans[i].ff - i) + dp(ans[i].ff);  
    }
    if(ans[i].ss != i){
        pdm = max(pdm, (ll)(i - ans[i].ss) + dp(ans[i].ss));
    }
    return pdm;
}

int main(){
    rvr(n);
    stack<pii> S;
    vi a(n);
    fr(i, n) scanf("%d", &a[i]), memo[i] = -1;
    fr(ii, n){
        int i = n - 1 - ii;
        while(!S.empty() && S.top().ff < a[i]) S.pop();
        if(S.empty()){
            ans[i].ff = i;
            S.push(mp(a[i], i));
            continue;
        }
        if(S.top().ff == a[i]){
            i = S.top().ss;
            S.pop();
        }
        ans[n - 1 - ii].ff = S.empty()?(n - 1 - ii):S.top().ss;
        S.push(mp(a[i], i));
    }
    while(!S.empty()) S.pop();
    fr(i, n){
        while(!S.empty() && S.top().ff < a[i]) S.pop();
        int plc = i;
        if(S.empty()){
            ans[i].ss = i;
            S.push(mp(a[i], i));
            continue;
        }
        if(S.top().ff == a[i]){
            plc = S.top().ss;
            S.pop();
        }
        ans[i].ss = S.empty()?i:S.top().ss;
        S.push(mp(a[i], plc));
    }
    fr(i, n) printf("%lld%c", dp(i), " \n"[i==n-1]);
}
