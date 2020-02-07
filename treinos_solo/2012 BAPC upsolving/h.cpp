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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int dist[1003][1003];
int n, w, h;
pii st[1009];
vector<pii> av[2009];

int distmh(pii a, pii b) {
    return abs(a.f-b.f) + abs(a.s-b.s);
}

bool check(int val) {
    
    int n = av[val].size();
    fr(i, n) {

        pii act1 = av[val][i];
        for (int j = i+1; j < n; j++) 
            if (distmh(act1, av[val][j]) >= val) 
                return 1;

        for (int nval = val+1; nval < h+w+2; nval++) 
            for (pii act2: av[nval]) 
                if (distmh(act1, act2) >= val) 
                    return 1;
    }

    return 0;
}

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        cin >> n >> w >> h;

        if (!n) {
            p(w+h-2);
            continue;
        }

        fr(i, w) fr(j, h) dist[i][j] = INF; 
        fr(i, h+w+2) av[i].clear();

        queue<pii> q;
        fr(i, n) {
            cin >> st[i].f >> st[i].s;
            dist[st[i].f][st[i].s] = 0;
            q.push({st[i]});
        }

        while (!q.empty()) {

            pii p = q.front();
            q.pop();

            int d = dist[p.f][p.s];
            fr(k, 4) {

                int ni = p.f + dx[k];
                int nj = p.s + dy[k];

                if (ni < 0 || ni >= w) continue;
                if (nj < 0 || nj >= h) continue;
                if (dist[ni][nj] < INF) continue;

                dist[ni][nj] = d+1;
                av[d+1].pb({ni, nj});
                q.push({ni, nj});
            }
        }

        int lo = 1, hi = w+h+1, ans = 0;
        while (lo <= hi) {
            int m = (lo+hi)>>1;
            if (check(m)) lo = m+1, ans = m;
            else hi = m-1;
        }

        p(ans);
    }
}
