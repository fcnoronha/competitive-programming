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

typedef vector<ll> pt;

ll dist(ll &ax, ll &ay, ll &az, ll&bx, ll&by, ll&bz) {
    return (ax-bx)*(ax-bx) + (ay-by)*(ay-by) + (az-bz)*(az-bz);
}

ll cube[8][3], ord[8][3], v[8][8];

bool check_cube() {
    

    map<ll, int> mp;

    bool oi = 0;
    for (int i = 1; i < 8; i++) {
        fr(k, 3) 
            if (ord[i][k] != ord[0][k])
                oi = 1;
    }
    if (oi && ord[0][0] != 0 && ord[0][1] != 1) return 0;

    for (int i = 0; i < 8; i++) 
    for (int j = i+1; j < 8; j++) {
        ll ax = cube[i][ord[i][0]], ay = cube[i][ord[i][1]], az = cube[i][ord[i][2]];
        ll bx = cube[j][ord[j][0]], by = cube[j][ord[j][1]], bz = cube[j][ord[j][2]];
        ll d = dist(ax, ay, az, bx, by, bz);
        mp[d] += 1;
        if (mp.size() > 3) return 0;
    }


    int c12 = 0, c4 = 0;
    for (auto aux: mp) {
        if (aux.s == 12) c12++;
        if (aux.s == 4)  c4++;
    }

    return c12 == 2 && c4 == 1;
}

bool rec(int idx) {

    if (idx == 8) return check_cube();

    ord[idx][0] = 0; ord[idx][1] = 1; ord[idx][2] = 2;
    do {

        // ll ax = cube[idx][ord[idx][0]], ay = cube[idx][ord[idx][1]], az = cube[idx][ord[idx][2]];

        // for (int j = idx-1; j >= 0; j--) {
            
        //     if (v[idx][j] != -1) {
        //         mp[v[idx][j]] -= 1;
        //         if (mp[v[idx][j]] == 0) {
        //             mp.erase(v[idx][j]);
        //         }
        //     }

        //     ll bx = cube[j][ord[j][0]], by = cube[j][ord[j][1]], bz = cube[j][ord[j][2]];
        //     ll d = dist(ax, ay, az, bx, by, bz);
        //     v[idx][j] = d;
        //     mp[d] += 1;
        // }

        // if (mp.size() > 3) continue;
        if (rec(idx+1)) return 1;
    
    } while (next_permutation(ord[idx], ord[idx]+3));

    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    fr(i, 8) {
        cin >> cube[i][0] >> cube[i][1] >> cube[i][2];
        fr(j, 8) v[i][j] = -1;
    }

    if (rec(0)) {
        p("YES");
        fr(i, 8)
            cout << cube[i][ord[i][0]] << ' ' << cube[i][ord[i][1]] << ' ' << cube[i][ord[i][2]] << endl; 
    }
    else {
        p("NO");
    }
}
