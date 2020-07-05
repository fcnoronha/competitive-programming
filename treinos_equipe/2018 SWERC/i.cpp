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

#define maxn 1123

int grid[maxn][maxn], seen[maxn][maxn];

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int mi, mj, n, m;

void dfs(int i, int j) {
    if (seen[i][j] || !grid[i][j]) return;
    seen[i][j] = 1;

    mi = max(mi, i), mj = max(mj, j);
    fr(k, 8) {
        int ii = i+dx[k];
        int jj = j+dy[k];
        if (ii < 0 || ii >= n) continue;
        if (jj < 0 || jj >= m) continue;
        dfs(ii, jj);
    }
}

int check(int mni, int mnj, int mxi, int mxj) {

    int hg = mxi - mni + 1, wg = mxj - mnj + 1;

    int x = -1, y = -1;
    for (int i = mni; i <= mxi; i++) {

        int c1 = 0, c2 = 0, c3 = 0;
        int j = mnj;

        while (j <= mxj && grid[i][j]) {
            c1++;
            j++;
        }
        while (j <= mxj && !grid[i][j]) {
            c2++;
            j++;
        }
        while (j <= mxj && grid[i][j]) {
            c3++;
            j++;
        }

        if (!c1 && c2 ) return 0;
        if (c3 && c1 != c3) return 0;
        
        if (c1 && c2 && c3 && x == -1 && y == -1) {
            x = c1;
            y = c2;
        }

        if (c1 && c2 && !c3 && x == -1) {
            x = c1;
            y = c2-c1;
        } 

        if (c1+c2+c3 != (x+y+x) && x != -1 ) return 0;//1
        if (c1 && c3 && c1 != x) return 0;
        if (c1 && c3 && c3 != x) return 0;
        if (c1 && c2 && !c3 && c2 != (x+y) && dbg(i)) return 0;
        if (c1 && !c2 && !c3 && x != -1 && c1 != (x+x+y)) return 0;
    }

    if (x == -1) return 0;
    if (!x || !y) return 0;
    if (x+y+x != wg) return 0;
    if (y+y+x+x+x != hg) return 0;

    for (int j = mnj; j <= mxj; j++) {

        int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
        int i = mni;

        while (i <= mxi && grid[i][j]) {
            c1++;
            i++;
        }
        while (i <= mxi && !grid[i][j]) {
            c2++;
            i++;
        }
        while (i <= mxi && grid[i][j]) {
            c3++;
            i++;
        }
        while (i <= mxi && !grid[i][j]) {
            c4++;
            i++;
        }
        while (i <= mxi && grid[i][j]) {
            c5++;
            i++;
        }

        if (c1 && !c2) continue;
        if (c1 != x) return 0;
        if (c2 != y && c2 != (y+y+x)) return 0;
        if (c3 && c3 != x) return 0;
        if (c4 && c4 != y && c4 != (y+x)) return 0;
        if (c5 && c5 != x) return 0;
    }

    int cntb = 0, cntw = 0;
    for (int i = mni; i <= mxi; i++) 
        for (int j = mnj; j <= mxj; j++) {
            if (grid[i][j]) cntb++;
            else            cntw++;
        }
    
    if (cntw == (y*y)+(y*y)+(x*y)) return 1;
    if (cntw == (y*y)+(y*y)) return 2;
    if (cntw == (y+x+y)*(y+x)) return 3;
    return 0;
}

int main() {
    fastio;

    int w, h;
    cin >> w >> h;

    n = h, m = w;
    fr(i, n) {
        string s;
        cin >> s;
        fr(j, m) {
            if (s[j] == '#') grid[i][j] = 1;
            else             grid[i][j] = 0;
        }
    }

    // removing noise
    frr(i, n-1) frr(j, m-1) {
        if (grid[i][j] == 0) continue;
        int cnt = 0;
        fr(k, 8) {
            int ii = i + dx[k];
            int jj = j + dy[k];
            cnt += (grid[ii][jj] == 0);
        }
        if (cnt == 8) 
            grid[i][j] = 0; 
    }

    int aa = 0, ab = 0, ac = 0;
    fr(i, n) fr(j, m) {
        if (seen[i][j] || !grid[i][j]) continue;
        mi = i, mj = j;
        dfs(i, j);

        if (mi == i || mj == j) continue;
        int oi = check(i, j, mi, mj);
        if (oi == 0) continue;
        if (oi == 1) aa++;
        if (oi == 2) ab++;
        if (oi == 3) ac++;
    }

    cout << aa << " " << ab << " " << ac << endl;
}
