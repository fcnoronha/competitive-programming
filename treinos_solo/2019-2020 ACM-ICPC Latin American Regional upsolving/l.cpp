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

int grid[maxn][maxn], cnt[maxn][maxn];
int n, m; 

int check(int v) {

    frr(j, m) {
        int aux = 0;
        frr(i, n) {

            if (cnt[i][j] < v) {
                aux = 0;
                continue;
            }

            aux++;
            if (aux == v) return 1;
        }
    }
    return 0;
}

int main(){
    fastio;

    cin >> n >> m;

    string s;
    frr(i, n) {
        cin >> s;
        frr(j, m) 
            if (s[j-1] == 'G') 
                grid[i][j] = 1;   
    }

    frr(i, n) cnt[i][1] = 1;
    frr(i, n) {
        frr(j, m) {
            if (j == 1) continue;
            if (grid[i][j] == grid[i][j-1]) 
                cnt[i][j] = cnt[i][j-1]+1;
            else 
                cnt[i][j] = 1;
        }
    }
    
    /* 
    frr(i, n) {
        frr(j, m) cout << cnta[i][j] << " ";
        cout << endl;
    }
    */

    int mn = 0, mx = 1010;
    fr(k, 50) {

        int m = (mn+mx)/2;
        if (check(m)) mn = m+1;
        else mx = m-1;
    }

    p(mx*mx);
}