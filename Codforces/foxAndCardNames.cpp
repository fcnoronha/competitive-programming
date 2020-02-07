//codeforces.com/problemset/problem/388/C

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

    ll n, s1 = 0, s2 = 0;
    vl aux;

    cin >> n;
    fr(i, n) {

        ll k, x;
        cin >> k;

        fr(j, k/2) {
            cin >> x;
            s1 += x;
        } 

        if (k%2) {
            cin >> x;
            aux.pb(x);
        }

        fr(j, k/2) {
            cin >> x;
            s2 += x;
        }
    }

    sort(all(aux));
    reverse(all(aux));

    for (int i = 0; i < aux.size(); i += 2) s1 += aux[i];
    for (int i = 1; i < aux.size(); i += 2) s2 += aux[i];

    cout << s1 << " " << s2 << endl;
}
