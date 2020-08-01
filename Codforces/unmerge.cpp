//codeforces.com/contest/1382/problem/D

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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int mx = 0, x;
        vi aux;
        frr(i, 2*n) {
            cin >> x;
            if (x > mx) {
                aux.pb(i);
                mx = x;
            }
        }
        aux.pb(2*n+1);

        vi ls;
        frr(i, aux.size()-1) ls.pb(aux[i]-aux[i-1]);

        int k = ls.size();
        bool memo[k+1][n+1];

        fr(i, k+1) memo[i][0] = 1;
        frr(i, n) memo[0][i] = 0;

        frr(i,k) frr(j, n) {
            memo[i][j] = memo[i-1][j];
            if (j >= ls[i-1]) memo[i][j] |= memo[i-1][j-ls[i-1]]; 
        } 

        if (memo[k][n]) p("YES");
        else p("NO");
    }
}
