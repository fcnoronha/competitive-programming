#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    string s;
    cin >> s;

    int n = s.size();
    int k = (1<<n);

    int xl = 0, xr = k, yl = 0, yr = k;

    //reverse(all(s));
    for (auto c : s) {

        if (c == '0') {
            xr = (xl+xr)/2;
            yr = (yl+yr)/2;
        }
        if (c == '1') {
            xl = (xl+xr)/2;
            yr = (yl+yr)/2;
        }
        if (c == '2') {
            xr = (xl+xr)/2;
            yl = (yl+yr)/2;
        }
        if (c == '3') {
            xl = (xl+xr)/2;
            yl = (yl+yr)/2;
        }

        //dbg(c);
        //cout << "x: "<< xl << " " << xr << endl;
        //cout << "y: "<< yl << " " << yr << endl;
    }

    cout << n << ' ' << xl << ' ' << yl << endl;
}
