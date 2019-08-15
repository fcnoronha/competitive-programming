//codeforces.com/contest/1200/problem/B

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 109

ll n, k, m, bag, h[maxn];

int main(){
    fastio

    int t;
    cin >> t;

    while (t--) {

        cin >> n >> m >> k;
        fr(i, n) cin >> h[i];
        bag = m;

        bool deu = 1;
        fr(i, n-1) {

            // demolishing column
            if (h[i]+k >= h[i+1]) {
                bag += min(h[i], h[i]+k - h[i+1]);
                continue;
            }

            // no da no
            if (h[i]+k+bag < h[i+1]) {
                deu = 0;
                break;
            }

            ll falta = h[i+1] - (h[i]+k);
            bag -= falta;
            continue;
        }

        if (deu) p("YES");
        else p("NO");
    }
}
