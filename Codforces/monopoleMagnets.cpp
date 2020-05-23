//codeforces.com/contest/1345/problem/D

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

#define maxn 1009
int hass_r[maxn], hass_c[maxn], hasn_r[maxn], hasn_c[maxn];
int grid[maxn][maxn], seen[maxn][maxn], cnt;
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int ii, int jj) {

    queue<pii> q;
    q.push({ii, jj});
    while (!q.empty()) {

        pii oi = q.front();
        q.pop();

        int i = oi.f;
        int j = oi.s;
        if (seen[i][j]) continue;
        seen[i][j] = 1;

        fr(k, 4) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni < 0 || ni >= n) continue;
            if (nj < 0 || nj >= m) continue;
            if (!grid[ni][nj]) continue;
            q.push({ni, nj});
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;
    
    fr(i, n) {
        string s;
        cin >> s;
        fr(j, m) {
            if (s[j] == '#') {
                grid[i][j] = 1;
                hasn_c[j] = hass_c[j] = 1;
                hasn_r[i] = hass_r[i] = 1;
            }
        }
    }

    fr(i, n) fr(j, m) {
        if (!hasn_r[i] && !hasn_c[j]) {
            hass_r[i] = 1;
            hass_c[j] = 1;
        }
    }

    int deu = 1;
    fr(i, n) if (!hass_r[i]) deu = 0;
    fr(i, m) if (!hass_c[i]) deu = 0;

    if (!deu) {
        p(-1);
        return 0;
    }

    fr(i, n) {
        int j = 0;
        while (j < m && !grid[i][j]) j++;
        while (j < m && grid[i][j]) j++;
        while (j < m && !grid[i][j]) j++;
        if (j != m) deu = 0;
    }
    fr(j, m) {
        int i = 0;
        while (i < n && !grid[i][j]) i++;
        while (i < n && grid[i][j]) i++;
        while (i < n && !grid[i][j]) i++;
        if (i != n) deu = 0;
    }
    
    if (!deu) {
        p(-1);
        return 0;
    }

    fr(i, n) {
        fr(j, m) {
            if (!seen[i][j] && grid[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    p(cnt);
}
