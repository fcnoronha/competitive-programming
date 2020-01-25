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

double calc(double l1, double l2, double d) {

    double aux = 0.0;

    double x = (l1*l1 - l2*l2 + d*d)/(2.0*d);

    double h = sqrt(l1*l1 - x*x);

    aux += (x*h)/2.0;
    aux += (d-x)*h/2.0;
    return aux;
}

int main(){
    fastio;

    double s[4];
    fr(i, 4) cin >> s[i];

    int perm[4] = {0,1,2,3};

    double ans = 0.0;
    do {

        double l[4];
        fr(i, 4) l[i] = s[perm[i]];

        double aux = 0.0;

        double lo = max( max(l[0], l[1])-min(l[0], l[1]), max(l[2], l[3])-min(l[2], l[3]) );
        double hi = min(l[0]+l[1], l[2]+l[3]);
        double eps = 1e-9;
        while (hi - lo > eps) {
            double m1 = lo + (hi-lo) / 3;
            double m2 = hi - (hi-lo) / 3;
            double f1 = calc(l[0], l[1], m1) + calc(l[2], l[3], m1);   
            double f2 = calc(l[0], l[1], m2) + calc(l[2], l[3], m2);     
            if (f1 < f2) 
                lo = m1;
            else
                hi = m2;
        }

        aux = calc(l[0], l[1], lo) + calc(l[2], l[3], lo); 

        ans = max(ans, aux);
 
    } while (next_permutation(perm, perm+4)); 

    cout << fixed << setprecision(7);
    p(ans);
}
