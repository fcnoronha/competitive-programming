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

int n, k, z;

int s[1123456], f[1123456];


int main(){
    scanf("%d%d", &n, &k);
    fr(i, n){
        int a; scanf("%d", &a);
        s[a] += 1;
        f[a + 1000] += 1;
        if(i == n-1) z = a+1000; 
    }

    int cnt = 0;
    int mx = -1;
    fr(i, z+1){
        cnt -= f[i];
        cnt += s[i];
        int v = cnt/k + (cnt%k != 0);
        mx = max(v, mx);
    }
    printf("%d\n", mx);

}
