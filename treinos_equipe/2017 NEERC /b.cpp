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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    ll v[3];
    fr(i, 3) cin >> v[i];
    ll w, h;
    cin >> w >> h;

    fr(i, 3) {
        fr(j, 3) {
            if (i==j) continue;
            fr(k, 3) {
                if (k == i || k == j) continue;
        
                fr(kkkk, 2) {
                    swap(w, h);
                    ll ww, hh;
                    
                    hh = 2ll*v[i] + 2ll*v[k];
                    ww = v[j] + 2ll*v[k];
                    
                    if (ww <= w && hh <= h) {
                        p("Yes");
                        return 0;
                    }

                    hh = 2ll*v[i] + 2ll*v[k];
                    ww = v[j] + 2ll*v[i];
                    
                    if (ww <= w && hh <= h) {
                        p("Yes");
                        return 0;
                    }

                    hh = 2ll*v[i] + 2ll*v[k];
                    ww = v[j] + v[i] + v[k];
                    
                    if (ww <= w && hh <= h) {
                        p("Yes");
                        return 0;
                    }

                    hh = 2ll*v[i] + 2ll*v[k];
                    ww = v[j] + 2ll*v[k];
                    
                    if (ww <= w && hh <= h) {
                        p("Yes");
                        return 0;
                    }

                    hh = 2ll*v[i] + v[k] + v[j];
                    ww = v[j] + 2ll*v[k];
                    
                    if (ww <= w && hh <= h) {
                        p("Yes");
                        return 0;
                    }

                    hh = v[i] + v[j] + v[k];
                    ww = v[i] + 2ll*v[k] + v[j];
                    
                    if (ww <= w && hh <= h) {
                        p("Yes");
                        return 0;
                    }

                    hh = v[i] + v[k];
                    ww = 3ll*v[j] + v[k] + v[i];
                    
                    if (ww <= w && hh <= h) {
                        p("Yes");
                        return 0;
                    }

                    hh = 2ll*v[j] + v[i] + v[k];
                    ww = v[i] + v[j] + v[k];
                    
                    if (ww <= w && hh <= h) {
                        p("Yes");
                        return 0;
                    }

                    hh = 2ll*v[i] + v[j] + v[k];
                    ww = v[j] + 2ll*v[k];
                    
                    if (ww <= w && hh <= h) {
                        p("Yes");
                        return 0;
                    }

                    hh = 2ll*v[k] + v[i];
                    ww = 2ll*v[j] + 2ll*v[k];
                    
                    if (ww <= w && hh <= h) {
                        p("Yes");
                        return 0;
                    }
                }
            }
        }
    }
    
    p("No");
}