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
#define tsts(t) rvr(t); while(t--)

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

int grid[10][10];

int main(){
    rvr(n);
    bool deu = true;
    fr(i, n){
        int d, l, r, c;
        scanf("%d%d%d%d", &d, &l, &r, &c);
        r--;
        c--;
        if(d){
            fr(j, l){
                if(r+j >= 10){
                    deu = false;
                    break;
                }
                grid[r+j][c]++;
                if(grid[r+j][c] > 1) deu = 0;
            }
        }
        else{
            fr(j, l){
                if(c+j >= 10){
                    deu = false;
                    break;
                }
                grid[r][c+j]++;
                if(grid[r][c+j] > 1) deu = 0;
            }
        }
    }
    if(deu) printf("Y\n");
    else printf("N\n");
}
