#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

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

struct coffee{
    int s, m, l;
};

map<string, coffee> M;

int main(){
    freopen("coffee.in", "r", stdin);
    fastio;
    int t; cin >> t;
    while(t--){
        M.clear();
        int c, p; cin >> c >> p;
        string s;
        fr(i, c){
            cin >> s;
            int S, m, l;
            cin >> S >> m >> l;
            M[s] = (coffee){S, m, l};
        }
        string name, size, cof;
        fr(i, p){
            cin >> name >> size >> cof;
            int otp = 100/p;
            if(size == "small"){
                otp += M[cof].s;
            }
            else if(size == "large"){
                otp += M[cof].l;
            }
            else{
                otp += M[cof].m;
            }
            if(otp%10 == 6 || otp%10 == 1) otp--;
            else if(otp%10 == 4 || otp%10 == 9) otp++;
            cout << name << " " << otp << "\n";
        }
        cout.flush();
    }

}
