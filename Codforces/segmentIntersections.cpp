//codeforces.com/contest/1389/problem/D

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
        ll n, k;
        cin >> n >> k;

        pll s1, s2;
        cin >> s1.f >> s1.s;
        cin >> s2.f >> s2.s;

        pll ss = min(s1, s2);
        s2 = max(s1, s2);
        s1 = ss;

        ll inter = 0ll, dist = 0ll, ans = LINF;
        if (s1.s > s2.f) {
            if (s2.s <= s1.s) inter = s2.s-s2.f;
            else              inter = s1.s - s2.f;
        }
        else                  dist = s2.f-s1.s;

        k -= inter*n;
        if (k <= 0) {
            p(0);
            continue;
        }

        ss = {min(s1.f, s2.f), max(s1.s, s2.s)};
        ll len = ss.s - ss.f, cst = 0ll;

        fr(i, n) {
            if (len - inter >= k) {
                cst += dist + k;
                ans = min(ans, cst);
                break;
            }
            cst += dist + len - inter;
            k -= len - inter;
            ans = min(ans   , cst + k + k);
        }

        p(ans);
    }
}   