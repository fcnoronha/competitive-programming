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
    //fastio;

    string keyp, s;
    getline(cin, keyp);
    getline(cin, s);

    string aux;
    for (auto c: s) if (c != ' ') aux += c;
    s = aux;

    map<char, bool> seen;
    map<char, pii> pos;
    map<pii, char> rpos;
    int idx = 0;

    for (auto c: keyp) {
        if (c == ' ') continue;
        if (seen[c]) continue;
        seen[c] = 1;
        pos[c] = {idx/5, idx%5};
        rpos[{idx/5, idx%5}] = c;
        idx++;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'q') continue;
        if (seen[c]) continue;
        pos[c] = {idx/5, idx%5};
        rpos[{idx/5, idx%5}] = c;
        idx++;
    }

    string ans;
    for (int i = 0; i < s.size(); i++) {

        char b1 = s[i], b2;
        if (i == (int)s.size()-1 || s[i] == s[i+1]) b2 = 'x';
        else {
            b2 = s[i+1];
            i++;
        }

        pii p1 = pos[b1], p2 = pos[b2];

        // same row
        if (p1.f == p2.f) {
            ans += rpos[{p1.f, (p1.s+1)%5}];
            ans += rpos[{p1.f, (p2.s+1)%5}];
        }
        // same col
        else if (p1.s == p2.s) {
            ans += rpos[{(p1.f+1)%5, p1.s}];
            ans += rpos[{(p2.f+1)%5, p1.s}];
        }
        else {
            ans += rpos[{p1.f, p2.s}];
            ans += rpos[{p2.f, p1.s}];
        }
    }

    for (auto x: ans) cout << (char)toupper(x);
    cout << endl;
}