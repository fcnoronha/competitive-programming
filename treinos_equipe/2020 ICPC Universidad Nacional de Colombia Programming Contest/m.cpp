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

    string s;
    cin >> s;

    int n, sz;
    cin >> n;
    sz = s.size();

    int oi[sz][26], crt[26];
    ms(oi, -1); ms(crt, -1);
    for (int i = sz-1; i >= 0; i--) {
        fr(k, 26) oi[i][k] = crt[k];
        crt[s[i]-'a'] = i;
    }

    while (n--) {
        string aux, ans;
        cin >> aux;
        int idx = crt[aux[0]-'a'], j = 0;
        while (idx != -1) {
            ans += aux[j++];
            if (j == aux.size()) break;
            idx = oi[idx][aux[j]-'a'];
        }

        if (ans.size() == 0) p("IMPOSSIBLE");
        else p(ans);
    }
}
