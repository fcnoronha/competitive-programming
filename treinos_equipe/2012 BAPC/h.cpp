#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define pv(x, n) fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])

#define p(x) cout << x << "\n"

#define f first
#define s second
#define mp make_pair
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const int N = 1e3 + 2;

int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int w, h;

vii stands;

vii memo[2222];

int dist[N][N], grid[N][N];

bool check(int pos, int max){
    return (pos >= 0 && pos < max);
}

void precalc(){
    queue<pii> q;
    for(auto p: stands) q.push(p);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        fr(k, 4){
            int nx = x + xx[k], ny = y + yy[k];
            if(check(nx, w) && check(ny, h) && grid[nx][ny] != -1 && dist[nx][ny] > dist[x][y] + 1){
                dist[nx][ny] = dist[x][y] + 1;
                memo[dist[nx][ny]].pb(mp(nx, ny));
                q.push(mp(nx, ny));
            }
        }
    }
}

bool bfs(int cur){
    for(int i = 0; i < memo[cur].size(); i++){
        for(int j = i + 1; j < memo[cur].size(); j++){
            if(abs(memo[cur][i].first - memo[cur][j].first) + abs(memo[cur][i].second - memo[cur][j].second) >= cur) return 1;
        }
        for(int k = cur + 1; memo[k].size() > 0; k++){
                for(auto p: memo[k]){
                    int x = p.first, y = p.second;
                    if(abs(memo[cur][i].first - x) + abs(memo[cur][i].second - y) >= cur) return 1;
                }
            }
    }
    return 0;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        stands.clear();
        ms(grid, 0);
        ms(dist, INF);
        int n; scanf("%d%d%d", &n, &w, &h);
        if(n == 0){
            printf("%d\n", w+h-2);
            continue;
        }
        fr(i, w + h +2) memo[i].clear();
        fr(i, n){
            int a, b; scanf("%d%d", &a, &b);
            stands.pb(mp(a, b));
            grid[a][b] = -1;
            dist[a][b] = 0;
        }
        precalc();
        int l = 1, r = h + w + 2;
        int ans = 1;
        while(l <= r){
            int mid = (l+r)/2;
            if(bfs(mid)){
                ans = max(ans, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        printf("%d\n", ans);
    }
}
