//onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2470

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

vector<int> get_lps(string p) {
    int len = 0; // size of last prefix sufix
    int n = p.size(), i = 1;
    vector<int> lps(n, 0);
    while (i < n) {
        if (p[i] == p[len]) 
            lps[i++] = ++len;
        else if (len != 0)
            len = lps[len-1];
        else 
            lps[i++] = 0;
    }
    return lps;
}

int kmp(string s, string t){
    vector<int> lps = get_lps(s);
    int m = s.size(), n = t.size();
    int i = 0, j = 0;
    while (i < n) {
        if (s[j] == t[i]) 
            j++, i++;
        if (j == m) {
            return m;
            j = lps[j-1];
        }
        if (i == n) {
            return j;
        }
        else if (i < n && s[j] != t[i]) {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}

int main() {
    fastio;

    string t;
    while (cin >> t) {
        
        string s = t;
        reverse(all(s));

        int i = kmp(s, t);
        cout << t;
        for (; i < s.size(); i++) cout << s[i];
        cout << endl;
    }
}
