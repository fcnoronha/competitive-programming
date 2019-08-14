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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

ll x[2123], y[2123];

bool used[2123];

bool goodsort(pii a, pii b){
    if(a.second < b.second) return 1;
    return 0;
}

bool hltsort(int a, int b){
    if(x[a] > x[b]) return 1;
    if(x[a] == x[b] && y[a] > y[b]) return 1;
    return 0;
}

bool btlsort(int a, int b){
    if(y[a] - x[a] < y[b] - x[b]) return 1;
    if(y[a] - x[a] == y[b] - x[b] && x[a] > x[b]) return 1;
    return 0;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        ll h; scanf("%lld", &h);
        int k; scanf("%d", &k);
        ms(used, false);
        vector<pii> good;
        vector<int> btl;
        vector<int> htl;
        fr(i, n){
            scanf("%lld%lld", &x[i], &y[i]);
            if(y[i] - x[i] >= 0) good.pb({y[i] - x[i], x[i]});
            else{
                htl.pb(i);
                btl.pb(i);
            }
        }
        sort(all(good), goodsort);
        sort(all(htl), hltsort);
        sort(all(btl), btlsort);

        int i, j;
        for(i = 0; i < good.size(); i++){
            if(h > good[i].second){
                h += good[i].first;
            }
            else break;
        }

        k -= (good.size() - i);

        i = 0; j = 0;

        if(htl.empty()){
            if(k >= 0) cout << "Y\n";
            else cout << "N\n";
            continue;
        }

        int tot = htl.size();
        while(j < btl.size() && i < htl.size()){
            while(j < btl.size() && used[j]) j++;
            while(i < htl.size() && used[i]) i++;
            if(j == btl.size() || i == htl.size()) break;
            if(i == j){
                if(h > x[htl[i]]){
                    h = h + y[htl[j]] - x[htl[j]];
                }
                else break;
                used[i] = 1;
                tot--;
                i++;
                j++;
            }
            else if(h + y[btl[j]] - x[btl[j]] > x[htl[i]]){
                h = h + y[btl[j]] - x[btl[j]];
                used[j] = 1;
                j++;
                tot--;
            }
            else{
                if(h > x[htl[i]]){
                    h = h + y[htl[i]] -x[htl[i]];
                    tot--;
                    used[i] = 1;
                    i++;
                }
                else break;

            }
        }

        k -= tot;
        if(k >= 0){
            cout << "Y\n";
        }
        else cout << "N\n";

    }

}
