//codeforces.com/contest/1348/problem/C

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

        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        sort(all(s));
        string ans[k];

        if (s[0] == s[n-1]) {
            int amt = (n+k-1)/k;
            fr(i, amt) cout << s[0];
            cout << endl;
            continue;
        }

        if (s[0] != s[k-1]) {
            p(s[k-1]);
            continue;
        }
        
        if (s[k] != s[n-1]) {
            for (int i = k-1; i < n; i++) cout << s[i];
            cout << endl;
            continue;
        }

        cout << s[k-1];
        int amt = (n-1)/k;
        while (amt--) cout << s[n-1];
        cout << endl;
    }
}
