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

#define maxn 70

long double dist[maxn][maxn], x[maxn], y[maxn], z[maxn];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;
    frr(tt, t) {

        int n;
        cin >> n;

        map<string, int> mp;
        fr(i, n) {
            string s;
            cin >> s;
            mp[s] = i;
            cin >> x[i] >> y[i] >> z[i];
        }

        fr(i, n) 
            fr(j, n) {
                if (i == j) {
                    dist[i][j] = 0.0;
                    continue;
                } 
                dist[i][j] = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) + (z[i]-z[j])*(z[i]-z[j]) );
            }

        int w;
        cin >> w;
        while (w--) {
            string u, v;
            cin >> u >> v;
            dist[mp[u]][mp[v]] = 0.0;
        }

        for (int k = 0; k < n; k++)
            for(int i = 0; i < n; i++) 
                for(int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        cout << "Case " << tt << ":\n";
        int q;
        cin >> q;
        while (q--) {
            string u, v;
            cin >> u >> v;

            long double ans = round(dist[mp[u]][mp[v]]);
            cout << setprecision(0) << fixed;
            cout << "The distance from " << u << " to " << v << " is "<< ans << " parsecs.\n";
        }
    }
}
