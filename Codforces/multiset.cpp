//codeforces.com/contest/1354/problem/D

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

vi v;

int check(int val) {

    int cnt = 0;
    for (auto x: v) {
        if (x > 0 && x <= val) cnt++;
        if (x < 0 && abs(x) <= cnt) cnt--;
    }

    return (cnt > 0);
}

int main() {
    fastio;

    int n, q;
    cin >> n >> q;
    fr(i, n+q) {
        int x;
        cin >> x;
        v.pb(x);
    }

    if (!check(INF)) {
        p(0);
        return 0;
    }

    int l = 0, r = INF, ans;
    fr(i, 100) {
        int m = (l+r)/2;
        if (check(m)) r = m;
        else          l = m;
    }

    p(r);
}
