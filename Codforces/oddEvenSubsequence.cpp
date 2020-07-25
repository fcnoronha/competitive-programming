//codeforces.com/contest/1370/problem/D

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

int a[maxn];
int n, k;

bool solve(int x, bool is) {

    int amt = 0, i = 0;
    while (amt < k && i < n) {
        if (!is || a[i] <= x) 
            amt++, is = !is;
        i++;
    }
    return (amt == k);
}

int main() {
    fastio;

    cin >> n >> k;
    fr(i, n) cin >> a[i];

    int ans = INF, l = 0, r = INF;
    fr(asuhsahasusuhsa, 100) {
        int m = (l+r)/2;

        if (solve(m, 0) || solve(m, 1)) {
            ans = min(ans, m);
            r = m;
        }
        else {
            l = m;
        }
    }

    p(ans);
}
