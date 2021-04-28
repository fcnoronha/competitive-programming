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

#define maxn 112345

int memo[2][maxn];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    string a, b;
    cin >> a >> b;

    int n = a.size();
    int ans = 0;
    int maxd = (n+99)/100;

    fr(i, n) {
        bool curi = i%2, lsti = !curi; 
        for (int j = max(0, i-maxd); j < min(n, i+maxd); j++) {

            int &pdm = memo[curi][j] = 0;
            if (a[i] == b[j]) {
                pdm = 1;
                if (i && j) pdm += memo[lsti][j-1];
            }
            
            if (j) pdm = max(pdm, memo[curi][j-1]);
            if (i) pdm = max(pdm, memo[lsti][j]);

            ans = max(ans, pdm);
        }
    }

    // dbg(ans);
    if (ans*100 >= n*99) p("Long lost brothers D:");
    else                 p("Not brothers :(");
}
