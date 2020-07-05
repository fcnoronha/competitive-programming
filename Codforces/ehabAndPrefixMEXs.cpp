//codeforces.com/contest/1364/problem/C

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
    int a[n], ans[n];
    fr(i, n) cin >> a[i];

    fr(i, n) 
        if (a[i] > i+1) {
            p(-1);
            return 0;
        }

    map<int, int> cnt;
    set<int> can;
    fr(i, n+n) can.insert(i); 

    for (int i = n-1; i >= 0; i--) {
        cnt[a[i]]++;
        if (can.count(a[i])) can.erase(a[i]);
    }

    fr(i, n) {
        ans[i] = *can.begin();
        can.erase(ans[i]);
        if (--cnt[a[i]] == 0) can.insert(a[i]);
    }

    fr(i, n) cout << ans[i] << " \n"[i == n-1];
}
