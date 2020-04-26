//codeforces.com/contest/1333/problem/D

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

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    string cfg;
    cin >> cfg;

    int mnk = 0, mxk = 0;
    string aux = cfg;
    bool tem = 1;
    vector<vi> ans;
    while (tem) {
        tem = 0;
        vi ax;
        fr(i, n-1) {
            if (aux[i] == 'R' && aux[i+1] == 'L') {
                tem = 1;
                mxk++;
                aux[i] = 'L';
                aux[i+1] = 'R';
                ax.pb(i+1);
                i++;
            }
        } 
        if (ax.size()) ans.pb(ax);
    }

    mnk = ans.size();
    if (k < mnk || k > mxk) {
        p(-1);
        return 0;
    }

    k -= mnk;
    for (auto v: ans) {

        int amt = min((int)v.size()-1, k);
        k -= amt;
        fr(i, amt) cout << "1 " << v[i] << '\n';
        cout << (int)v.size()-amt << " ";
        for (int i = amt; i < v.size(); i++) cout << v[i] << " ";
        cout << '\n';
    } 
}
