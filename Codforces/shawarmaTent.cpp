//codeforces.com/contest/1271/problem/C

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

    int n, sx, sy;
    cin >> n >> sx >> sy;

    int x, y, no = 0, su = 0, le = 0, oe = 0;
    fr(i, n) {
        cin >> x >> y;

        if (y > sy) no++;
        if (y < sy) su++;
        if (x > sx) le++;
        if (x < sx) oe++;
    }

    int mx = max({no,su,le,oe});
    if (su == mx) {
        cout << su << endl << sx << " " << sy-1 << endl;
        return 0;
    } 
    if (no == mx) {
        cout << no << endl << sx << " " << sy+1 << endl;
        return 0;
    } 
    if (le == mx) {
        cout << le << endl << sx+1 << " " << sy << endl;
        return 0;
    } 
    if (oe == mx) {
        cout << oe << endl << sx-1 << " " << sy << endl;
        return 0;
    } 

}
