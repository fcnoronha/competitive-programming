//www.spoj.com/problems/EDIST/

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
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int memo[2009][2009];
string s1, s2;

int dp(int i, int j) {

    int &dpm = memo[i][j];
    if (~dpm) return dpm;

    if (!i)
        return dpm = j;

    if (!j)
        return dpm = i;

    // no operation needed
    if (s1[i-1] == s2[j-1])
        return dpm = dp(i-1, j-1);

    dpm = dp(i-1, j);             // deleted
    dpm = min(dpm, dp(i, j-1));   // inserted
    dpm = min(dpm, dp(i-1, j-1)); // substitute

    return dpm += 1;
}

int main(){
    fastio

    int t;
    cin >> t;

    while (t--) {

        cin >> s1 >> s2;

        ms(memo, -1);
        int ans = dp(s1.size(), s2.size());

        p(ans);
    }
}
