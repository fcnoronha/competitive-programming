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
#define EPS 1e-8

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;


void run(){

    /*
    string s;
    double l;
    ll n;

    cin>>s>>l>>n;

    int i;
    for(i=0;i<s.size()and s[i]!='.';++i);

    char v[s.size()];
    fr(j,s.size()) v[j]=s[j];

    double aa;
    sscanf(v,"%lf",&aa);

    int a;
    if(i==s.size())
        a=aa;
    else
        a=aa*pow(10,(s.size()-i-1));

    if(a==0){
        cout<<n*l<<' '<<0<<endl;
        return;
    }


    int mmc=a*360/__gcd(a,360);
    */

    double s, l;
    int n, mod = -1;
    cin >> s >> l >> n;

    double ang=-s,x=0,y=0;

    fr(i,n){

        ang=(ang+s);

        x+=cos( ang*acos(-1)/180.0 )*l;
        y+=sin( ang*acos(-1)/180.0 )*l;

        if (x < EPS && y < EPS) {
            mod = i+1;
            break;
        }
    }

    if (mod == -1) {
        cout<<fixed<<setprecision(5)<< x <<' '<< y <<endl;
        return;
    }

    ang = -s, x = 0.0, y = 0.0;
    fr(i, n%mod) {
        ang=(ang+s);

        x+=cos( ang*acos(-1)/180.0 )*l;
        y+=sin( ang*acos(-1)/180.0 )*l;
    }
    cout<<fixed<<setprecision(5)<< x <<' '<< y <<endl;
}

int main(){
    fastio;
    int t;

    cin>>t;
    while(t--) run();

}
