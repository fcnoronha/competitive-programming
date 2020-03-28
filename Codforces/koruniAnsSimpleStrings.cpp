//codeforces.com/contest/1305/problem/B

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

int main() {
    fastio;

    string s;
    cin >> s;

    int n = s.size();
    s = '*'+s+'*';

    vector<int> ans; 
    int l = 1, r = n;
    while (l < r) {
        while (l <= n && s[l] == ')') l++;
        while (r >= 1 && s[r] == '(') r--;
        if (l < r && l <= n && r >= 1) {
            ans.pb(l);
            ans.pb(r);
            l++;
            r--;
        }
    }

    sort(all(ans));
    if (ans.size()) {
        p(1);
        p(ans.size());
        pv(ans);
    }
    else p(0);
}
