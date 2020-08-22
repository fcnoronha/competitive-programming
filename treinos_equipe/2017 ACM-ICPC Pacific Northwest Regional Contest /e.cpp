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
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

double li[112], ri[112], vi[112];
double x, v, dtx;
int n;

int foi = 0;

double f(double vy) {
    double vx = sqrt(v*v - vy*vy);
    double sm = 0.0;
    fr(i, n) 
        sm += (vi[i]+vy)*(ri[i]-li[i])/vx;
    sm += dtx*vy/vx;

    if (abs(sm) < 0.0000001) foi = 1;
    return abs(sm);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    cin >> n >> x >> v;

    dtx = x;
    fr(i, n) {
        cin >> li[i] >> ri[i] >> vi[i];
        dtx -= ri[i]-li[i];
    }

    double l = -v, r = v;
    fr(kkk, 100) {
        double m1 = l + (r-l) / 3.0;
        double m2 = r - (r-l) / 3.0;
        double f1 = f(m1);   
        double f2 = f(m2);     
        if (f1 > f2) l = m1;
        else		 r = m2;
    }

    double vx = abs(l);
    vx = sqrt(v*v - vx*vx);
    double ans = x/vx;

    if (ans >= 2.0*x/v || !foi) 
        p("Too hard");
    else 
        cout << setprecision(3) << fixed << x/vx << endl;
}
