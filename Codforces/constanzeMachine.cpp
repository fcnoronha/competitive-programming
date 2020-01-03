//codeforces.com/contest/1245/problem/C

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

const ll mod = 1e9+7;

ll mul[100009];

int main(){
    fastio;

    mul[1] = 1;
    mul[2] = 2;

    string s;
    cin >> s;

    for (int i = 3; i <= s.size(); i++) 
        mul[i] = (mul[i-1]+mul[i-2])%mod;

    fr(i, s.size()) {
        if (s[i] == 'm' || s[i] == 'w') {
            p("0");
            return 0;
        }
    }

    ll ans = 1ll, aux = 1ll;
    char lst = s[0];

    s += "$";
    frr(i, s.size()-1) {

        if (s[i] != lst) {

            if (lst != 'n' && lst != 'u') aux = 1;

            ans = (ans*mul[aux])%mod;
            aux = 1ll;
            lst = s[i];
            continue;
        }
        aux++;
    }

    p(ans);
}
