//codeforces.com/contest/1291/problem/B

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

#define maxn 300009

ll a[maxn], inc[maxn], dc[maxn];

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        fr(i, n) {
            cin >> a[i];
            inc[i] = min(a[i], ll(i));
            dc[i] = min(a[i], ll(n-i-1));
        }

        frr(i, n-1) inc[i] += inc[i-1];
        for (int i = n-2; i >= 0; i--) dc[i] += dc[i+1];


        fr(i, n) {

            int l = max(i-1, 0);
            int r = min(i+1, n-1);

            ll ri = max(i, n-i-1);

            ll sml = (ll(i)*ll(i-1))/2ll;
            ll smr = (ll(n-i-1)*ll(n-i-2))/2ll;


            if (inc[l] == sml && dc[r] == smr && a[i] >= ri) {
                p("Yes");
                goto fim;
            } 
        }

        p("No");
        fim:;
    }
}
