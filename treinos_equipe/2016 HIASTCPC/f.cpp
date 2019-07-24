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

int memo[11234][112], m[112], accum[112];

int N;

int dp(int s, int i){

    if(i == N) return abs(2*s - accum[i]);

    if(memo[s][i] == -1){
        memo[s][i] = max(abs(2*s - accum[i]), min(dp(s + m[i], i + 1), dp(s, i + 1)));
    }

    return memo[s][i];

}

int main(){
    int t; scanf("%d", &t);
    while(t--){
	    scanf("%d", &N);

        ms(memo, -1);

        fr(i, N) {
            scanf("%d", &m[i]);
            accum[i+1] = accum[i] + m[i];
        }

        printf("%d\n", dp(0, 0));

    }
}
