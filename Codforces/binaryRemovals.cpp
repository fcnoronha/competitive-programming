//codeforces.com/contest/1499/problem/B

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int n = s.size();

        int c1 = 0, c0 = 0, df = 1;
        fr(i, n) {

            if (s[i]=='1') c1++;
            else c0++;

            if (i && s[i-1]==s[i]) df = 0; 
        }

        if (c1 == n || c0 == n || df) {
            p("YES");
            continue;
        }

        bool x = 0, deu = 1;
        for (int i = 1; i < n-1; i++) {
            if (s[i] == '1') continue;
            if (s[i-1] == s[i] || s[i] == s[i+1]) deu = 0;
        }
        if (deu) {
            p("YES");
            continue;
        }

        deu = 1;
        for (int i = 1; i < n-1; i++) {
            if (s[i] == '0') continue;
            if (s[i-1] == s[i] || s[i] == s[i+1]) deu = 0;
        }
        if (deu) {
            p("YES");
            continue;
        }

        deu = 1;
        for (int i = 1; i < n-1; i++) {
            if (s[i] == '0'+x) continue;
            if (s[i-1] == s[i] || s[i] == s[i+1]) {
                if (x) deu = 0;
                x = 1;
            }
        }
        if (deu) {
            p("YES");
            continue;
        }

        if (deu) p("YES");
        else p("NO");
    }
}
