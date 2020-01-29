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

int main(){
    fastio;

    ll a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    ll n1 = b1-a1+1;
    ll n2 = b2-a2+1;

    ll gun = 0;
    for (ll a = a1; a <= b1; a++) 
        for (ll b = a2; b <= b2; b++) 
            gun += (a+b);

    ll g = __gcd(gun, n1*n2);
    gun /= g; 
    ll dg = (n1*n2)/g;
    
    cin >> a1 >> b1 >> a2 >> b2;

    n1 = b1-a1+1;
    n2 = b2-a2+1;

    ll emm = 0;
    for (ll a = a1; a <= b1; a++) 
        for (ll b = a2; b <= b2; b++) 
            emm += (a+b);

    g = __gcd(emm, n1*n2);
    emm /= g; 
    ll de = (n1*n2)/g;

    if ((emm == gun && de == dg)) p("Tie");
    else if (double(emm)/double(de) > double(gun)/double(dg)) p("Emma");
    else p("Gunnar");
}
 