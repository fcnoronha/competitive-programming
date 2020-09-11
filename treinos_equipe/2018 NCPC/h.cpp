#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll WK = 10080;

int main(){
    fastio;
    int l, m; cin >> l >> m;
    vector<string> otp;
    int ans = INF;
    string lixo;
    getline(cin, lixo);
    fr(i, m){
        string s;
        getline(cin, s);
        int j = 0, n = s.size();
        string name;
        while(s[j] != ',') name.pb(s[j++]);
        int c = 0, t=0, r = 0, p = 0;
        j++;
        while(s[j] != ',') p*=10, p+=(s[j] - '0'), j++;
        j++;
        while(s[j] != ',') c*=10, c+=(s[j] - '0'), j++;
        j++;
        while(s[j] != ',') t*=10, t+=(s[j] - '0'), j++;
        j++;
        while(s[j] >= '0' && s[j] <= '9') r*=10, r+=(s[j] - '0'), j++;
        ll lf = WK*(ll)(c*t), rgt = (ll)(l)*(ll)(t+r);
        if(lf >= rgt){
            if(ans > p){
                otp.clear();
                otp.push_back(name);
                ans = p;
            }
            else if(ans == p) otp.pb(name);
        }
    }
    if(ans == INF){
        cout << "no such mower\n";
        return 0;
    }
    for(auto s: otp){
        cout << s << endl;
    }
}
