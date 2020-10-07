//codeforces.com/contest/1418/problem/C

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

#define maxn 212345

int memo[maxn][2][2]; // i, player, moves
int a[maxn];
int n;

int pd(int i, bool p, bool mv) {

    if (i >= n) return 0; 
    int &pdm = memo[i][p][mv];

    if (pdm != -1) return pdm;
    pdm = (a[i] == 1 && p == 0);

    int aux = INF;
    if (mv == 0) aux = pd(i+1, p, 1);
    aux = min(aux, pd(i+1, !p, 0));

    return pdm+=aux;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;
    while (t--) {
        
        cin >> n;
        fr(i, n) cin >> a[i];

        fr(i, n+10) fr(j, 2) fr(k, 2) memo[i][j][k] = -1;

        p(pd(0,0,0));
    }
}
