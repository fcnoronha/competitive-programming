#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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

        int io = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '-' || s[i] == '+' || s[i] == '*') {
                io = i;
                break;
            }
        }

        map<char, bool> isin;
        vector<string> v;
        string cur;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            isin[c] = 1;
            if (c == '+' || (i == io && c == '-') || c == '*') {
                string aux;
                aux += s[i];
                v.pb(cur);
                v.pb(aux);
                cur.clear();
                continue;
            }
            if (c == '=') {
                v.pb(cur);
                cur.clear();
                continue;
            }
            cur += c;
        }
        v.pb(cur);


        int deu = 0;
        for (char dd = '0'; dd <= '9'; dd++) {

            if (isin[dd]) continue;

            if (dd == '0') {
            if (v[0].size() > 1 && v[0][0] == '?') continue;
            if (v[0].size() >= 2 && v[0][0] == '-' && v[0][1] == '?') continue;
            if (v[2].size() > 1 && v[2][0] == '?') continue;
            if (v[2].size() >= 2 && v[2][0] == '-' && v[2][1] == '?') continue;
            if (v[3].size() > 1 && v[3][0] == '?') continue;
            if (v[3].size() >= 2 && v[3][0] == '-' && v[3][1] == '?') continue;
            }

            vector<string> aux;
            for (auto x: v) {
                string ss;
                for (auto c: x) {
                    if (c == '?') {
                        ss += dd;
                        continue;
                    }
                    ss += c;
                }
                aux.pb(ss);
            }

            ll n1 = stoll(aux[0]);
            ll n2 = stoll(aux[2]);
            ll re = stoll(aux[3]);

            if (v[1] == "-") {
                if (n1-n2 == re) {
                    deu = 1;
                    p(dd);
                    break;
                }
            }
            if (v[1] == "+") {
                if (n1+n2 == re) {
                    deu = 1;
                    p(dd);
                    break;
                }
            }
            if (v[1] == "*") {
                if (n1*n2 == re) {
                    deu = 1;
                    p(dd);
                    break;
                }
            }
        }

        if (!deu) p(-1);
    }
}
