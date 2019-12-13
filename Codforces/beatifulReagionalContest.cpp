#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

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

        int n, g=0, s=0, b=0, aux;
        cin >> n;

        map<int, int> amt;
        fr(i, n) {
            cin >> aux;
            amt[aux]++;
        }

        vi v;
        for (auto a : amt) v.pb(a.s);
        reverse(all(v));

        g = v[0];
        int i = 1;

        int on = n;
        n = v.size();
        while (i < n && g >= s) s += v[i++];

        if (i == n) {
            cout << "0 0 0\n";
            continue;
        }

        while (i < n && g >= b) b += v[i++];
        while (i < n && g+s+b+v[i] <= (on/2)) b += v[i++];

        if (g+s+b <= on/2) 
            cout << g << " " << s << " " << b << endl;
        else 
            cout << "0 0 0\n";
    } 
}
