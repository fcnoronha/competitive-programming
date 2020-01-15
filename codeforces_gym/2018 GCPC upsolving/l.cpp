#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(iii, x.size()) cout << x[iii] << " \n"[iii==x.size()-1]
#define pvv(x, n) for(int iii = 1, vaca = nnn; i <= nnn;i++) cout << x[i] << " \n"[iii==nnn];

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

int h, w;
int grid[109][109], ans[109][109];

int main(){
    fastio;

    cin >> h >> w;

    fr(i, h+2) fr(j, w+2) 
        cin >> grid[i][j];
    
    int dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
    int dy[9] = {1, -1, 0, 1, -1, 0, 1, -1, 0};

    int amt = 0;
    frr(i, h) {
        frr(j, w) {

            if (grid[i-1][j-1] <= 0) continue;
            ans[i][j] = 1;

            fr(k, 9) {

                int ni = i + dx[k];
                int nj = j + dy[k];
                grid[ni][nj]--;
            }
        }
    }

    int check = 1;
    fr(i, h+2) 
        fr(j, w+2) 
            if (grid[i][j] != 0)
                check = 0;

    if (!check) {
        p("impossible");
        return 0;
    }

    frr(i, h) {
        frr(j, w) {
            if (ans[i][j]) cout << "X";
            else cout << ".";
        }
        cout << endl;
    }
}
