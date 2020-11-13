//codeforces.com/contest/1435/problem/B

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

        int n, m;
        cin >> n >> m;

        int a1[n][m], a2[n][m];
        map<int, int> mp;

        fr(i, n) fr(j, m) {
            cin >> a1[i][j];
            mp[a1[i][j]] = i;
        }
        
        fr(j, m) fr(i, n) {
            cin >> a2[i][j];
        }

        fr(i, n) {
            int ii = mp[a2[i][0]];
            fr(j, m) cout << a1[ii][j] << " ";
            cout << endl;
        }
    }
}
