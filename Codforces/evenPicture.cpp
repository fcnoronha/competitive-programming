//codeforces.com/contest/1368/problem/C

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

int main() {
    fastio;

    int n;
    cin >> n;

    int m = n*5;
    string s[m];
    fr(i, m)
        fr(j, m)
            s[i] += '.';

    pii oi[7] = {{0,0}, {1,0}, {2,0}, {0,1}, {2,1}, {0,2}, {1,2}};
    fr(k, 7) s[oi[k].s][oi[k].f] = '#';

    frr(i, n) {
        int a = i*2;
        fr(k, 7) 
            s[oi[k].s+a][oi[k].f+a] = '#';
    }
    s[(n+1)*2][(n+1)*2] = '#';

    int cnt = 0;
    fr(i, m) fr(j, m) cnt += (s[i][j]=='#');
    p(cnt);
    fr(i, m) fr(j, m) if (s[i][j]=='#')
        cout << i << ' ' << j << endl;
}
