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

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i, r = i+z[i]-1;
    }
    return z;
}

int main() {
    fastio;

    int n;
    cin >> n;
    string s;
    cin >> s;

    int memo[n][n];
    ms(memo, -1);

    fr(sz, n) {
        fr(i, n) {
            int j = i+sz, lf = j-i+1, comp = lf;
            if (j >= n) continue;
            if (j == i) {
                memo[i][j] = 1;
                continue;
            }
            int &pdm = memo[i][j];
            pdm = lf;

            for (int k = i; k < j; k++) 
                pdm = min(pdm, memo[i][k]+memo[k+1][j]);

            vi z = z_function(s.substr(i, lf));
            frr(k, lf-1) 
                if (lf%k == 0 && k+z[k] == lf) 
                    comp = min(comp, k);

            pdm = min(pdm, comp);
            pdm = min(pdm, memo[i][i+comp-1]);
        }
    }

    p(memo[0][n-1]);
}
