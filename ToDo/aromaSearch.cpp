//codeforces.com/contest/1293/problem/D

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

ll dist(pll a, pll b) {
    return abs(a.f-b.f)+abs(a.s-b.s);
}

int main(){
    fastio;

    pll x, a, b, s;
    cin >> x.f >> x.s >> a.f >> a.s >> b.f >> b.s;

    ll t;
    cin >> s.f >> s.s >> t;

    ll ans = 0;

    vector<pll> pts;
    pts.pb(x);
    
    while (1) {

        pll novo;
        novo.f = a.f*x.f;
        novo.s = a.s*x.s;

        if (novo.f < 0 || novo.s < 0) break;

        novo.f += b.f;
        novo.s += b.s;
        
        if (novo.f < 0 || novo.s < 0) break;

        pts.pb(novo);
        x = novo;
    }

    // for (auto u: pts) dbg(u.f ), dbg(u.s);

    fr(i, pts.size()) {

        pll ori = pts[i];

        ll aux = dist(ori, s);
        if (aux > t) continue;

        ll cnt = 0;
        ll l = i-1, r = i+1;

        while (aux <= t) {
            
            cnt++;

            if (l >= 0 && r < pts.size()) {
                
                if (dist(pts[l], pts[l+1]) < dist(pts[r], pts[r-1])) {
                    aux += dist(pts[l], pts[l+1]);
                    l--;
                }
                else {
                    aux += dist(pts[r], pts[r-1]);
                    r++;
                }
            }

            else if (l >= 0) {
                aux += dist(pts[l], pts[l+1]);
                l--;
            }

            else if (r < pts.size()) {
                aux += dist(pts[r], pts[r-1]);
                r++;
            }   

            else 
                break;
        }

        ans = max(ans, cnt);
    }

    p(ans);
}

