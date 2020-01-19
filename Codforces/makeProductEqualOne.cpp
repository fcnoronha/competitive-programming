//codeforces.com/contest/1206/problem/B

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

    ll n;
    cin >> n;

    ll neg = 0, ans = 0, aux, zero = 0;
    fr(i, n) {

        cin >> aux;
        
        if (aux == 0) {
            if (zero) ans++;
            else zero = 1;
            continue;
        }

        if (aux > 0) ans += (aux-1);
        else ans += (abs(aux)-1), neg++;
    }

    if (neg%2) {
        if (zero) ans++;
        else ans += 2;
    }
    else if (zero) ans++;

    p(ans);
}
