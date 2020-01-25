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
const int N = 1e5 + 2;

int pref[N][3], cnt[3];

int main(){
    fastio;
    int n; cin >> n;
    string s; cin >> s;
    frr(i, n){
        cnt[s[i-1]-'A']++;
        fr(j, 3) pref[i][j] = cnt[j];
    }
    vi vaca = {0, 1, 2};
    int ans = 1e5 + 3;
    do{
        int a = vaca[0], b = vaca[1], sa = cnt[a], sb = cnt[b]; 
        int tam = sa + sb;
        frr(i, n - tam){
            int da = sa - (pref[i+sa - 1][a] - pref[i-1][a]);
            int db = sb - (pref[i+tam - 1][b] - pref[i+sa][b]);
            int r = min(pref[i+tam-1][a] - pref[i+sa][a], pref[i+sa-1][b] - pref[i-1][b]);
            db += r;
            
            ans = min(ans, da + db);
        }
    }while(next_permutation(all(vaca)));
    cout << ans << endl;
}
