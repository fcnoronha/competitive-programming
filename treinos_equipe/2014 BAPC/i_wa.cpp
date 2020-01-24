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

    ll t;
    cin >> t;

    ll fib[50], n = 1;
    fib[1] = fib[2] = 1;
    for (int i = 2;; i++) {
        fib[i] = fib[i-1]+fib[i-2];
        if (fib[i] > 1000000000) break;
        n++;
    }
   
    while (t--) {

        ll num;
        cin >> num;

        pll ans = {LINF, LINF};

        ll lim = (num+1)/2;
        for (ll i = n; i > 0; i--) {

            ll f1 = fib[i-1];
            ll f2 = fib[i];

            for (ll b = 1; b <= 100000; b++) {

                if ((num - b*f2)%f1) continue;
                ll a = (num - b*f2)/f1; 

                if (a <= 0) break;
                if (a > b) continue;
                ans = {a, b};
                goto fim;
            }
        }

        fim:;
        if (ans.f == LINF) ans = {num/2, (num+1)/2};
        cout << ans.f << " " << ans.s << endl;
    }
}