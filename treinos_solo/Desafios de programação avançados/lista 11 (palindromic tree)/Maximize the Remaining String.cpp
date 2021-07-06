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

    int t; cin >> t;
    while (t--) {
        
        string s; cin >> s;

        map<char, int> f;
        map<char, bool> usd;
        for (auto c: s) f[c]++;

        fr(i, s.size()) {

            map<char, int> seen;
            string ss;
            int bst = i;
            for (int j = i; j < s.size(); j++) {
                seen[s[j]]++;
                if (s[j] > s[bst]) bst = j;
                if (f[s[j]] == seen[s[j]]) break;
            }

            usd[s[bst]] = 1;
            for (int j = i; j < bst; j++) f[s[j]]--;

            for (int j = 0; j < i; j++) ss += s[j];
            ss += s[bst];
            for (int j = bst+1; j < s.size(); j++)
                if (!usd[s[j]]) ss += s[j];

            s = ss;
            // dbg(s);
        }

        p(s);
    }
}
