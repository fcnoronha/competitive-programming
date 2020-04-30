//vjudge.net/contest/370837#problem/D

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

#define maxn 112345

int n, m, k;
int cst[26][26], freq[maxn][26], memo[maxn][26];
string s;

int solve(int i, int j) {

    if (i < k || memo[i][j] < INF) return memo[i][j];
    int &pdm = memo[i][j];
    pdm = solve(i-1, j) + cst[s[i]-'a'][j];
    int c = freq[i][j] - freq[i-k][j];
    fr(l, m) pdm = min(pdm, solve(i-k, l) + c);

    return pdm;
}

int main() {
    fastio;

    cin >> n >> m >> k;
    cin >> s;
    fr(i, m) fr(j, m) cin >> cst[i][j];
    
    // Awnnn how cute the little floyd-warshall
    fr(k, m) fr(i, m) fr(j, m)
        cst[i][j] = min(cst[i][j], cst[i][k] + cst[k][j]);

    fr(i, n) {
        fr(j, m) freq[i][j] = cst[s[i]-'a'][j];
        if (i == 0) continue;
        fr(j, m) freq[i][j] += freq[i-1][j];
    }

    ms(memo, INF);
    fr(i, m) memo[k-1][i] = freq[k-1][i];
    fr(i, m) solve(n-1, i);
    int ans = INF;
    fr(i, m) ans = min(ans, memo[n-1][i]); 
    p(ans);
}

