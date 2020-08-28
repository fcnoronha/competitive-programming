#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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

#define maxn 4123456

bool grid[2001][2001], vis[maxn];
vector< pair<int, char> > adj[maxn];

int n, m, gg[2019][2001], ri[maxn], rj[maxn];

int cord(int i, int j) {
    return i*m + j;
}

void adde(int i, int j, int ii, int jj, char vai, char vem) {
    adj[cord(i,j)].pb({cord(ii,jj), vai});
    adj[cord(ii,jj)].pb({cord(i,j), vem});
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    cin >> n >> m;

    int str, end;
    fr(i, n) {
        string s;
        cin >> s;
        fr(j, m) {
            if (s[j] == 'X') grid[i][j] = 1;
            if (s[j] == 'S') str = cord(i, j);
            if (s[j] == 'E') end = cord(i, j);
            ri[cord(i,j)] = i;
            rj[cord(i,j)] = j;
        }
    }

    fr(i, n) {
        fr(j, m) {
            if (grid[i][j]) continue;
            if (j < m-1 && !grid[i][j+1]) adde(i,j,i,j+1,'R','L');
            if (i < n-1 && !grid[i+1][j]) adde(i,j,i+1,j,'D','U');
            if (j < m-1 && grid[i][j+1]) {
                for (int jj = j+1; jj < m; jj++) {
                    if (grid[i][jj]) continue;
                    adde(i,j,i,jj,'R','L');
                    break;
                }
            } 
            if (i < n-1 && grid[i+1][j]) {
                for (int ii = i+1; ii < n; ii++) {
                    if (grid[ii][j]) continue;
                    adde(i,j,ii,j,'D','U');
                    break;
                }
            }
        }
    }

    ms(gg, INF);
    queue<pii> qu;
    qu.push({end,0});
    while (!qu.empty()) {
        pii aux = qu.front();
        qu.pop();
        int u = aux.f, dd = aux.s;

        if (vis[u]) continue;
        vis[u] = 1, gg[ri[u]][rj[u]] = dd;

        for (auto xx: adj[u]) {
            int v = xx.f;
            if (vis[v]) continue;
            qu.push({v,dd+1});
        }
    }

    if (gg[ri[str]][rj[str]] == INF) {
        p("-1");
        return 0;
    }

    string ans;
    vi cur;
    cur.pb(str);
    while (1) {
        pair<int, char> mn = {INF, 'z'};
        for (auto u: cur) {
            for (auto x: adj[u]) {
                int v = x.f;
                char c = x.s;
                mn = min(mn, (pair<int,char>){gg[ri[v]][rj[v]], c});
            }
        }

        vi vv;
        ans += mn.s;
        for (auto u: cur) {
            for (auto x: adj[u]) {
                int v = x.f;
                char c = x.s;
                if (pair<int,char>{gg[ri[v]][rj[v]], c} != mn) continue;
                if (v == end) goto fim;
                vv.pb(v);
            }
        }
        cur = vv;
    }

    fim:;
    p(ans.size());
    p(ans);
}
