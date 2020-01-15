//onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int cut[52];
int cst[52][52];
int n;

int pd(int i, int j) {

    if (i+1 >= j) return 0;

    int &pdm = cst[i][j];
    if (pdm != -1) return pdm;

    pdm = INF;
    int size = cut[j]-cut[i];
    for (int k = i+1; k < j; k++)
        pdm = min(pdm, pd(i,k)+pd(k,j)+size);
    return pdm;
}

int main(){
    fastio;

    int l;
    while (cin >> l && l) {

        cin >> n;

        frr(i, n) cin >> cut[i];
        cut[++n] = l;
        cut[0] = 0;

        ms(cst, -1);
        int ans = pd(0, n);

        cout << "The minimum cutting is " << ans << ".\n";
    }
}
