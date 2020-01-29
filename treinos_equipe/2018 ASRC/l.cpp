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
const int N = 2222;

int lf[N], d[N], rm[N];
int n, m, h, w;

vector<pii> push[N];

vi ans[N];

int calc(int i){
    return n + 1 - lf[i] - (lf[i]/w - 1)*h;
} 

int main(){
    scanf("%d%d%d%d", &m, &n, &w, &h);
    set<pii> active;
    fr(i, m){
        scanf("%d", &lf[i]);
        active.insert(make_pair(calc(i), i));
    }
    frr(i, n) scanf("%d", &d[i]);
    int workers = 0;
    bool deu = true;
    vector<pii> tkout;
    frr(i, n){
        tkout.clear();
        workers -= rm[i];
        int diff = d[i] - workers;
        if(diff < 0){
            deu = false;
            goto END;
        }
        for(auto p: push[i]) active.insert(p);
        if(active.size() < diff){
            deu = false;
            goto END;
        }
        int cnt = 0;
        for(auto p: active){
            if(cnt == diff) break;
            if(p.first < i){
                deu = false;
                goto END;
            }
            tkout.pb(p);
            cnt++;
            lf[p.second] -= w;
            if(lf[p.second] > 0) push[w+h+i].pb(make_pair(calc(p.second), p.second)); 
            rm[i+w]++;
            ans[p.second].pb(i);
        }
        for(auto p: tkout) active.erase(p);
        workers = d[i];
    }
    END:
    if(!deu){
        printf("-1\n");
    }
    else{
        printf("1\n");
        fr(i, m){
            int sz = ans[i].size();
            fr(j, sz) printf("%d%c", ans[i][j], " \n"[j==sz-1]);
        }
    }
}
