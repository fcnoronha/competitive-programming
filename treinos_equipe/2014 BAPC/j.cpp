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

pii ori[4] = {{0,1}, {1,0}, {0, -1}, {-1,0}};

int grid[300][300];

int main(){
    fastio;

    int t;
    cin >> t;
    cout << t << endl;

    map<char, int> mov;
    mov['F'] = 0;
    mov['R'] = 1;
    mov['B'] = 2;
    mov['L'] = 3;

    while (t--) {

        int h_min = 105, w_min = 0, h_max = 105, w_max = 0;

        ms(grid, 0);

        string s;
        cin >> s;

        pii pos = {105, 0};
        grid[pos.f][pos.s] = 1;
        int idx = 0;
        for (auto m: s) {

            idx = (idx+mov[m])%4;
            pos.f += ori[idx].f;
            pos.s += ori[idx].s;
            grid[pos.f][pos.s] = 1;

            h_min = min(h_min, pos.f);
            h_max = max(h_max, pos.f);
            
            w_min = min(w_min, pos.s);
            w_max = max(w_max, pos.s);
        }

        cout << (h_max-h_min)+3 << " " << w_max+2 << endl;

        for (int i = h_min-1; i <= h_max+1; i++) {
            for (int j = 0; j <= w_max+1; j++){
                if (grid[i][j]) cout << '.';
                else cout << '#'; 
            }
            cout << endl;
        }
    }
}