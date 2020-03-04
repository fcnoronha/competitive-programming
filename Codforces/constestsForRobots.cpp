//codeforces.com/contest/1321/problem/A

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

    int n;
    cin >> n;
    int r[n], b[n];
    fr(i, n) cin >> r[i];
    fr(i, n) cin >> b[i];

    int only_r = 0, cnt_r = 0, cnt_b = 0;
    fr(i, n) {
        if (r[i] && !b[i]) only_r++;
        cnt_r += r[i];
        cnt_b += b[i];
    }

    if (only_r == 0 && cnt_b >= cnt_r) {
        p(-1);
        return 0;
    }

    if (cnt_b < cnt_r) {
        p(1);
        return 0;
    }  

    cout << ((cnt_b - cnt_r + only_r) / only_r)+1 << endl;
}
