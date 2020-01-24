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

int w, h, si, sj;
int grid[maxn][maxn], fire[maxn][maxn], dist[maxn][maxn];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs_fire() {

    queue<pii> q;

    fr(i,h) {
        fr(j,w) {
            fire[i][j] = INF;
            if (grid[i][j] == 1) {
                fire[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while (!q.empty()) {

        int i = q.front().f;
        int j = q.front().s;
        q.pop();

        int f = fire[i][j];

        fr(k, 4) {

            int ni = i+dx[k];
            int nj = j+dy[k];

            if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if (grid[ni][nj] == 2) continue; 

            if (fire[ni][nj] > f+1) {
                fire[ni][nj] = f+1;
                q.push({ni, nj});
            }
        }
    }
}

int bfs() {

    queue<pii> q;

    fr(i,h) {
        fr(j,w) {
            dist[i][j] = INF;
        }
    }

    dist[si][sj] = 0;
    q.push({si, sj});

    while (!q.empty()) {

        int i = q.front().f;
        int j = q.front().s;
        q.pop();

        int d = dist[i][j];

        if (i == 0 || j == 0 || i == h-1 || j == w-1) return d+1;

        fr(k, 4) {

            int ni = i+dx[k];
            int nj = j+dy[k];

            if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if (grid[ni][nj] == 2) continue;

            if (d+1 < fire[ni][nj] && dist[ni][nj] > d+1) {
                dist[ni][nj] = d+1;
                q.push({ni, nj});
            }
        }
    }

    return -1;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        cin >> w >> h;

        string s;
        fr(i, h) {

            cin >> s;
            fr(j, w) {

                grid[i][j] = 0;

                if (s[j] == '*') grid[i][j] = 1;
                if (s[j] == '#') grid[i][j] = 2;
                if (s[j] == '@') si = i, sj = j;
            }
        }

        bfs_fire();
        int ans = bfs();

        if (ans == -1) p("IMPOSSIBLE"); 
        else p(ans);
    }

}