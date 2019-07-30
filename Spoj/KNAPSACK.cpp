//www.spoj.com/problems/KNAPSACK/

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;


const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int s, n;
int memo[2009][2009];
int sz[2009], vl[2009];

int dp(int idx, int left) {

    int &pdm = memo[idx][left];

    if (idx == n || !left) return pdm = 0;
    if (~pdm) return pdm;

    if (sz[idx] <= left)
        return pdm = max( vl[idx]+dp(idx+1, left-sz[idx]), dp(idx+1, left) );

    return dp(idx+1, left);
}

int main(){
    fastio

    cin >> s >> n;

    fr(i, n)
        cin >> sz[i] >> vl[i];

    ms(memo, -1);
    p(dp(0, s));
}
