//codeforces.com/contest/1323/problem/C

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
    string s;
    cin >> s;

    int cnto = 0, cntc = 0;
    for (auto c: s) {
        if (c == '(') cnto++;
        else cntc++;
    }

    if (cntc != cnto) {
        p(-1);
        return 0;
    }

    int ans = 0, cnt = 0, lst = -1;
    fr(i, n) {
        if (s[i] == '(') {
            cnt++;
            if (cnt == 0) {
                ans += i-lst+1;
                lst = -1;
            }
        }
        else {
            cnt--;
            if (cnt == -1) {
                lst = i;
            }
        }
    }

    p(ans);
}
