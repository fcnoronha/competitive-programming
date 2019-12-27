//codeforces.com/contest/1271/problem/B

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

int main(){
    fastio;

    int n;
    cin >> n;

    string so;
    cin >> so;

    string s = so;
    vi ans;
    
    map<char, char> inv;
    inv['W'] = 'B';
    inv['B'] = 'W';

    // to W
    fr(i, n-1) {

        if (s[i] == 'B') {
            ans.pb(i+1);
            s[i+1] = inv[s[i+1]];
        } 
    }

    if (s[n-1] == 'W') {
        p(ans.size());
        pv(ans);
        return 0;
    }

    // to b;
    s = so;
    ans.clear();
    fr(i, n-1) {
        if (s[i] == 'W') {
            ans.pb(i+1);
            s[i+1] = inv[s[i+1]];
            s[i] = inv[s[i]];
        } 
    }

    if (s[n-1] == 'B') {
        p(ans.size());
        pv(ans);
        return 0;
    }

    p("-1");
}
