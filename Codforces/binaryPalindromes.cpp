//codeforces.com/contest/1251/problem/B

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

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        pair<int, string> s[n];
        fr(i, n) cin >> s[i].s, s[i].f = s[i].s.size();
        
        sort(s, s+n);
        int zero = 0, one = 0;
        
        fr(i, n) for (char c: s[i].s) {
            if (c == '0') zero++;
            if (c == '1') one++;
        }

        int ans = 0;
        fr(i, n) 
            if (s[i].f%2) {
                if (one%2) one--;
                else zero--;
            }
        
        ans = n;
        if (one%2 && zero%2) ans--;

        p(ans);
    }
}
