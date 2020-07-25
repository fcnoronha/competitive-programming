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

#define double long double

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<double,double> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

pll pt[112];

double dist(pll a, pll b) {
    return sqrt((a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s)); 
}

double ts(pll a, pll b, pll p) {
    double l = 0.0, r = 1.0;
    fr(uhashusahasuh, 100) {
        double m1 = l+(r-l)/3;
        double m2 = r-(r-l)/3;
        pll p1 = {a.f*m1+b.f*(1.0-m1), a.s*m1+b.s*(1.0-m1)};
        pll p2 = {a.f*m2+b.f*(1.0-m2), a.s*m2+b.s*(1.0-m2)};
        double f1 = dist(p1, p);   
        double f2 = dist(p2, p);     
        if (f1 > f2) l = m1;
        else		 r = m2;
    }
    pll p1 = {a.f*l+b.f*(1.0-l), a.s*l+b.s*(1.0-l)};
    return dist(p1, p);   
}

double tss(pll a, pll b, pll p, pll q) {
    double l = 0.0, r = 1.0;
    fr(uasuhashuas, 100) {
        double m1 = l+(r-l)/3;
        double m2 = r-(r-l)/3;
        pll p1 = {a.f*m1+b.f*(1.0-m1), a.s*m1+b.s*(1.0-m1)};
        pll p2 = {a.f*m2+b.f*(1.0-m2), a.s*m2+b.s*(1.0-m2)};
        double f1 = ts(p, q, p1);   
        double f2 = ts(p, q, p2);     
        if (f1 > f2) l = m1;
        else		 r = m2;
    }
    pll p1 = {a.f*l+b.f*(1.0-l), a.s*l+b.s*(1.0-l)};
    return ts(p, q, p1);   
}

int main() {
    fastio;

    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m, k;
    cin >> n >> m >> k;
    fr(i, n) cin >> pt[i].f >> pt[i].s;

    double ans = 1000000000000.0;
    fr(i, n) 
        for (int j = i+2; j < n; j++) {
            int s1 = j-i+1, s2 = n-j+1+i;
            if (min(s1,s2)==min(m,k) && max(s1,s2)==max(m,k)) 
                ans = min(ans, dist(pt[i], pt[j]));
        }
    
    fr(i, n) 
        fr(j, n) {
            int s1, s2;
            if (j >= i)
                s1 = j-i+2, s2 = n-j+1+i;
            else
                s1 = i-j+1, s2 = n-i+2+j;
            if (min(s1,s2)==min(m,k) && max(s1,s2)==max(m,k)) 
                ans = min(ans, ts(pt[j], pt[(j+1)%n], pt[i]));
        }
    
    fr(i, n) 
        for (int j = i+1; j <= n; j++) {
            int s1 = j-i+2, s2 = n-j+2+i;
            if (min(s1,s2)==min(m,k) && max(s1,s2)==max(m,k)) {
                ans = min(ans, tss(pt[(j)%n], pt[(j+1)%n], pt[(i)%n], pt[(i+1)%n]));
                ans = min(ans, tss(pt[(i)%n], pt[(i+1)%n], pt[(j)%n], pt[(j+1)%n]));
            }
        }

    if (ans == 1000000000000.0) p(-1);
    else cout << setprecision(3) << fixed << ans << endl;
}
