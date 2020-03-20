//codeforces.com/contest/1326/problem/D2

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

vi lps;

int LPS(string pat){

    string aux = pat;
    aux += '&';
    reverse(all(pat));
    aux += pat;
    swap(aux, pat);

    int M = pat.size();
    int len = 0;

    lps.clear();
    lps.resize(M+1);
    lps[0] = 0; 

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return M;
}

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
        string oi;
        for (int i = l; i < r; i++) oi+=s[i];
        if (r == s.size()-1) oi += s[r];
        int tt = LPS(oi);
        int sz = lps[tt-1]; 
        for (int i = l; i < l+sz; i++) aux += s[i];

        oi = "";
        if (l == 0) oi += s[0];
        for (int i = l+1; i <= r; i++) oi += s[i];
        reverse(all(oi));
        tt = LPS(oi);
        sz = lps[tt-1];
        if (sz > aux.size()) {
            aux = "";
            for (int i = r; i > r-sz; i--) aux += s[i];
        }

        if (aux.size()) cout << aux;

        for (auto c: ans) 
            if (c != '&')
                cout << c;

        cout << endl;
    }
}
