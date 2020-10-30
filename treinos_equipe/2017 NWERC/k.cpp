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

int main(){
    rvr(n);
    vi a(n);
    fr(i, n) scanf("%d", &a[i]);
    a[0] *= -1;
    vector<vector<pair<int, long double>>> cur;
    sort(all(a));
    int j = 1;
    while(2*j <= n) j *= 2;
    fr(i, n){
        vector<pair<int, long double>> plc;
        if(n - i <= 2*(n-j)){
            plc.pb(mp(a[i], (long double)abs(a[i])/(long double)(abs(a[i]) + abs(a[i+1]))));
            plc.pb(mp(a[i+1], (long double)abs(a[i+1])/(long double)(abs(a[i]) + abs(a[i+1]))));
            i++;
        }
        else plc.pb(mp(a[i], 1));
        cur.pb(plc);
    }
    while(cur.size() > 1){
        
        int i = 0;
        vector<vector<pair<int, long double>>> plc;
        while(i < cur.size()){
            vector<pair<int, long double>> vaca;
            if(i == 0){
                long double temp = 0;
                for(auto p: cur[i+1]){
                    temp += (((long double)abs(cur[i][0].ff))/(long double)(abs(cur[i][0].ff)+p.ff))*p.ss;
                }
                temp *= cur[i][0].ss;
                vaca.pb(mp(cur[i][0].ff, temp));
                plc.pb(vaca);
            }
            else{
                for(auto p: cur[i]){
                    long double temp = 0;
                    for(auto pp: cur[i+1]){
                        temp += (((long double)p.ff)/(long double)(p.ff+pp.ff))*pp.ss;
                    }
                    temp *= p.ss;
                    vaca.pb(mp(p.ff, temp));
                }
                for(auto p: cur[i+1]){
                    long double temp = 0;
                    for(auto pp: cur[i]){
                        temp += (((long double)p.ff)/(long double)(p.ff+pp.ff))*pp.ss;
                    }
                    temp *= p.ss;
                    vaca.pb(mp(p.ff, temp));
                }
                plc.pb(vaca);
            }
            i += 2;
        }
        swap(plc, cur);
    }
    printf("%.6Lf\n", cur[0][0].ss);
}