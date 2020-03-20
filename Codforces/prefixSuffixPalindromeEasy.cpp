#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
//codeforces.com/contest/1326/problem/D1


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
        
        string s;
        cin >> s;

        vector<char> ans(s.size(), '&');
        if (s.size() == 1) {
            p(s);
            continue;
        }

        int l = 0, r = s.size()-1;
        while (l <= r) {
            if (s[l] != s[r]) break;
            ans[l] = s[l];
            ans[r] = s[r];
            l++;
            r--;
            continue;
        }

        for (auto &c: ans) { 
            if (c == '&') break; 
            cout << c;
            c = '&';
        }

        string aux = "";

        fr(d, s.size()) {

            string auxx;
            int i = l;
            int j = r-d;
            if (j < i) break;
            int isp = 1;
            while (i < j) {
                if (s[i] != s[j]) {
                    isp = 0;
                    break;
                }
                i++;
                j--;
            } 
            if (!isp) continue;
            for (i = l; i <= r-d; i++) auxx+=s[i];
            if (auxx.size() > aux.size()) aux = auxx;
        }

        fr(d, s.size()) {

            string auxx;
            int i = l+d;
            int j = r;
            if (j < i) break;
            int isp = 1;
            while (i < j) {
                if (s[i] != s[j]) {
                    isp = 0;
                    break;
                }
                i++;
                j--;
            } 
            if (!isp) continue;
            for (i = l+d; i <= r; i++) auxx+=s[i];
            if (auxx.size() > aux.size()) aux = auxx;
        }

        if (aux.size()) cout << aux;

        for (auto c: ans) 
            if (c != '&')
                cout << c;

        cout << endl;
    }
}
