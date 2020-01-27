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

pii a[22];

int md[22], h[22], mx = -1;

int main(){
    int n; scanf("%d", &n);
    fr(i, n){
        scanf("%d", &h[i]);
        mx = max(mx, h[i]);
        int aa, bb; scanf("%d%d", &aa, &bb);
        a[i] = make_pair(aa, bb);
        if(bb > aa) md[i] = 1;
    }
    for(int i = 0; i <= 1825*mx; i++){
        bool wrk = true;
        fr(j, n){
            int cur = i%h[j];
            if(md[j]){
                if(cur > a[j].first && cur < a[j].second){
                    wrk = false;
                    break;
                }
            }
            else{
                if(cur > a[j].first || cur < a[j].second){
                    wrk = false;
                    break;
                }
            }
        }
        if(wrk){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("impossible\n");
}
