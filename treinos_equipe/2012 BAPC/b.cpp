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
    //fastio;

    int t;
    cin >> t;

    cin.clear();
    while (t--) {

        cout << "5 1 5 6" << endl;
        cout << flush;
        cout.clear();

        string md;
        while (cin >> md) {

            if (md == "GAME") break;

            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;

            cin.clear();
            
            int nr1 = 4-r1+1;
            int nr2 = 4-r2+1;
                
            int nc2 = 6-c1+1;
            int nc1 = 6-c2+1;

            cout << min(nr1, nr2) << " " << min(nc1, nc2) << " " << max(nr1, nr2) << " " << max(nc1, nc2) << endl;
            cout << flush;
            cout.clear();
        }
    }
}
