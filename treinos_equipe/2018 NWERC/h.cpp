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

#define maxn 512345

int n, c, b;
bool ans[maxn], no[maxn];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    cin >> n >> c >> b;

    fr(i,b) {
        int z;
        cin >> z;
        no[z-1] = 1;
    }

    int cur = 1;
    if (c%2) ans[0] = 1, c--, cur++;
    
    while (c) {
        while (no[cur]) cur++;
        ans[cur] = 1;
        c -= 2;
        cur += 2;
    }

    fr(i, n) cout << ans[i];
    cout << endl;
}
