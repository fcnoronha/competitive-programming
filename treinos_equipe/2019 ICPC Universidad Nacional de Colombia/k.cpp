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

#define maxn 112345

int fib[maxn], ans[maxn];

int main() {
    fastio;

    fib[1] = fib[2] = 1;
    ans[1] = ans[2] = 0;
    fib[3] = 0;
    ans[3] = 2;
    for (int i = 4; i <= 100001; i++) {
        fib[i] = (fib[i-1]+fib[i-2])%2;
        ans[i] = ans[i-1];
        if (fib[i-1]+fib[i] == 1) ans[i]++;
    }

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        p(ans[x]);
    }
}