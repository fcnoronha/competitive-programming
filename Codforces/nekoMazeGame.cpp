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

#define maxn 100009

int avlb[3][maxn];

int main(){
    fastio;

    int n, q;
    cin >> n >> q;

    int dx[6] = {-1, -1, -1, 1, 1, 1};
    int dy[6] = {-1, 0, 1, -1, 0, 1};

    int cnt = 0;
    fr(i, q) {
        
        int x, y;
        cin >> x >> y;

        if (avlb[x][y] == 0) {
            avlb[x][y] = 1;
            fr(k, 6) {

                int nx = x+dx[k];
                int ny = y+dy[k];

                if (nx < 1 || nx > 2 || ny < 1 || ny > n) continue; // OLHA 
                if (avlb[nx][ny]) cnt++;
            }
        }
        else {
            avlb[x][y] = 0;
            fr(k, 6) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (nx < 1 || nx > 2 || ny < 1 || ny > n) continue; // OLHA 
                if (avlb[nx][ny]) cnt--;
            }
        }

        if (cnt) p("NO");
        else p("YES");
    }
}
