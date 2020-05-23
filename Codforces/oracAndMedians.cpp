//codeforces.com/contest/1350/problem/D

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

int solve() {
    int n, k;
    cin >> n >> k;
    int a[n], tem = 0;
    fr(i, n) {
        int x;
        cin >> x;

        if (x == k) {
            a[i] = 1;
            tem = 1;
        }
        else if (x < k) {
            a[i] = 0;
        }
        else {
            a[i] = 2;
        }
    }

    if (!tem) return 0;
    if (n == 1) return 1;
    fr(i, n) {
        for (int j = i+1; j < n && j-i < 3; j++) {
            if (a[i] && a[j]) return 1;
        }
    }
    return 0;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        if (solve()) p("yes");
        else p("no");
    }
}
