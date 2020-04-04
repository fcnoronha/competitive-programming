//codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c

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
    fastio;
    int t;
    cin >> t;
    frr(tt, t) {

        int n;
        cin >> n;
        int grid[n][n], seen[n+1];
        fr(i, n) fr(j, n) cin >> grid[i][j];
        
        int trace = 0;
        fr(i, n) trace += grid[i][i];

        int coiso = (n*(n+1))/2, r = 0, c = 0;
        fr(i, n) {

            fill(seen, seen+n+1, 0);
            fr(j, n) seen[ grid[i][j] ]++;
            frr(k, n) 
                if (seen[k] != 1) {
                    r++;
                    break;
                }

            fill(seen, seen+n+1, 0);
            fr(j, n) seen[ grid[j][i] ]++;
            frr(k, n) 
                if (seen[k] != 1) {
                    c++;
                    break;
                }

        }

        cout << "Case #" << tt << ": " << trace << " " << r << " " << c << '\n';
    }
}
