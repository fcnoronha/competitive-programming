#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
    
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;

double n, p, s, v;
double f(double c){
    double a = n*pow(log2(n),c*sqrt(2.0))/((double)p*1e9);
    a += (double)s*(1.0+(1.0/c))/v;
    return a;
}


void ternary_search(double l, double r) {
    double eps = 1e-12;              
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      
        double f2 = f(m2);      
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    cout << fixed;
    cout << setprecision(10);
    cout << f(l) << " " << l << endl;                  
}

int main(){
    fastio;
    
    cin >> n >> p >> s >> v;
    ternary_search(0, 1e9);


}