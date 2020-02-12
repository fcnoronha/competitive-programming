//codeforces.com/contest/1291/problem/C

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

#define maxn 4000

int a[maxn];

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int n, m, k;
        cin >> n >> m >> k;

        fr(i, n) cin >> a[i];

        int ans = 0;
        int l = 0, r = n-1;
        k = min(k, m-1);

        r -= k;
        fr(ji, k+1) {

            int rst = m-k-1;

            int auxans = INF;
            if (rst == 0) auxans = max(a[l], a[r]);

            int auxl = l+rst;
            int auxr = r;

            fr(i, rst) {
                auxans = min(auxans, max(a[auxl], a[auxr]));
                auxl--;
                auxr--;
            }
            auxans = min(auxans, max(a[auxl], a[auxr]));

            //if (auxans > ans) dbg(r), dbg(l);
            r++; l++;
            ans = max(ans, auxans);
        }

        p(ans);
    }
}
