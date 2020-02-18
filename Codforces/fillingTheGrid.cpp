//codeforces.com/contest/1228/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

const ll mod = 1000000007;
int grid[1009][1009];

ll fastexp(ll base, ll exp){
	if (!exp) return 1;
	ll ans = fastexp(base, exp/2);
	ans = (ans*ans)%mod;
	if (exp%2) ans = (ans*base)%mod;
	return ans%mod; 
}

int main(){
    fastio;

    int h, w;
    cin >> h >> w;

    int k;
    int vld = 1;
    fr(i, h) {
        cin >> k;
        fr(j, k) grid[i][j] = 3;
        grid[i][k] = 1;
    }
    fr(i, w) {
        cin >> k;
        fr(j, k) {
            if (grid[j][i] == 1) vld = 0;
            grid[j][i] = 3;
        }
        if (grid[k][i] == 3) vld = 0;  
        grid[k][i] = 1;
    }

    ll cnt = 0ll;
    fr(i, h) fr(j, w) 
        if (grid[i][j] == 0) cnt++;

    if (!vld) p("0");
    else p(fastexp(2ll, cnt));
}
