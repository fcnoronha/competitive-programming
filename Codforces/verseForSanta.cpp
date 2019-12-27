//codeforces.com/contest/1279/problem/B

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

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int n, s;
        cin >> n >> s;

        int a[n+1];
        frr(i, n) cin >> a[i];
        a[0] = 0;

        int idx = 0, rst = s, tudo = 0;
        frr(i, n) {
            if (a[i] > a[idx]) idx = i;
            if (rst < a[i]) break;
            
            rst -= a[i];
            if (i == n) tudo = 1;
        }

        if (tudo) idx = 0;
        p(idx);
    }
}
