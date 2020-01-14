//codeforces.com/contest/1272/problem/C

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

    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    char afb[k];
    fr(i, k) cin >> afb[i];

    s += '$';
    ll ans = 0;
    ll aux = 0;

    for (auto c: s) {

        bool tem = 0;
        fr(i, k) tem |= (afb[i] == c);

        if (tem) {
            aux++;
            continue;
        }

        ans += (aux*(aux+1))/2;
        aux = 0;
    }

    p(ans);
}
