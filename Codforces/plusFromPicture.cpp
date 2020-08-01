//codeforces.com/contest/1182/problem/B

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
    fastio;

    int h, w;
    cin >> h >> w;

    string s[h];
    fr(i, h) cin >> s[i];

    pii cc = {-1, -1}, cr = {-1,-1};
    fr(i, h) {
        int aux = 0;
        fr(j, w) aux += (s[i][j] == '*');
        if (aux <= 1) continue;
        if (cr.f != -1) {
            p("NO");
            return 0;
        }
        cr = {aux, i};
    }

    fr(i, w) {
        int aux = 0;
        fr(j, h) aux += (s[j][i] == '*');
        if (aux <= 1) continue;
        if (cc.f != -1) {
            p("NO");
            return 0;
        }
        cc = {aux, i};
    }

    if (cc.f == -1 || cr.f == -1) {
        p("NO");
        return 0;
    }

    int i = cr.s;
    int j = cc.s;

    if (i == 0 || i == h-1 || j == 0 || j == w-1) {
        p("NO");
        return 0;
    }

    if (s[i][j] == '.' || s[i][j+1] == '.' || s[i][j-1] == '.' || s[i+1][j] == '.' || s[i-1][j] == '.') {
        p("NO");
        return 0;
    }

    int ii = i+1;
    while (ii < h && s[ii][j] == '*') s[ii++][j] = '.';
    ii = i-1;
    while (ii >= 0 && s[ii][j] == '*') s[ii--][j] = '.';

    int jj = j+1;
    while (jj < w && s[i][jj] == '*') s[i][jj++] = '.';
    jj = j-1;
    while (jj >= 0 && s[i][jj] == '*') s[i][jj--] = '.';
    s[i][j] = '.';

    fr(i,h) fr(j,w) if (s[i][j] == '*') {
        p("NO");
        return 0;
    }

    p("YES");
}
