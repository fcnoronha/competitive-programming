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

double pd[1001][1001];

int main(){
    fastio;

    int n, x, y;
    while(cin >> n >> x >> y){
        
        for(int i = 1; i<=n; i++) pd[x][1] = 1.0;
        for(int y = 2; y<=n; y++){
            double v = 1.0;
            for(int x = 1; x<=n; x++){
                double s = pd[x-1][y-1]*(1.0-(2.0/n-(y-1.0))*(1.0/(n-(y+1.0)-1.0))) + (1-pd[x-1][y-1]);
                pd[x][y] = pd[x][y-1]*v*s;
                dbg(pd[x][y]);
                v *= s;
            }
        }

        cout << pd[x][n-y+1]*(1 - pd[x][n-y+2]) << endl;
    }


}
