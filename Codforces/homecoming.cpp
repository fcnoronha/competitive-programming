//codeforces.com/contest/1315/problem/B

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

    int t;
    cin >> t;

    while (t--) {

        ll a, b, p;
        cin >> a >> b >> p;
        string s;
        cin >> s;
        ll n = s.size();
        int ans = n-1;
        vl amt(n+1, 0);
        n--;
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                amt[i] = (s[i]=='A')*a + (s[i]=='B')*b;
                if (amt[i] > p) break;
                ans = i;
                continue;
            }
            amt[i] = amt[i+1];
            if (s[i] != s[i+1]) 
                amt[i] += (s[i]=='A')*a + (s[i]=='B')*b;
            if (amt[i] > p) break;
            ans = i;
        }
        p(ans+1);
    }
}
