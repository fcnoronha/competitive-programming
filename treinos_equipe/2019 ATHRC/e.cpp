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
const ll A = 1e6, N = 2e3;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

pll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return {-1, -1};
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return {-1, -1};


    if(x > 0 && x <= maxx && y >= miny && y <= maxy && a*x + b* y == c){
        return {x, y};
    }    

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);



    if(x > 0 && x <= maxx && y >= miny && y <= maxy && a*x + b* y == c){
        return {x, y};
    }

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return {-1, -1};
    if(x > 0 && x <= maxx && y >= miny && y <= maxy && a*x + b* y == c){
        return {x, y};
    }

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);

    if(x > 0 && x <= maxx && y >= miny && y <= maxy && a*x + b* y == c){
        return {x, y};
    }
    return {-1, -1};
}

int main(){
    ll t; scanf("%lld", &t);
    while(t--){
        ll k, l; scanf("%lld%lld", &k, &l);
        if(l > N){
            printf("-1\n");
            continue;
        }
        vll ans;
        bool deu = false;
        for(ll i = 1; i <= N - 1; i++){
            for(ll j = 1; j <= N - i; j++){
                ll x0, y0, g;
                pll val = find_all_solutions(j, i+j, k, 1, i*A, -j*A, -1);
                if(val.first != -1){
                    deu = true;
                    int cnt = 0;
                    while(val.first > 0)
                    {
                        if(cnt == i - 1){
                            ans.pb(val.first);
                            break;
                        }
                        ans.pb(((val.first)/i + ((val.first%i) > 0)));
                        val.first -= ((val.first)/i + ((val.first%i) > 0));
                        cnt++;
                    }
                    cnt = 0;
                    val.second *= -1;
                    while(val.second > 0)
                    {
                        if(cnt == j - 1){
                            ans.pb(-val.second);
                            cnt++;
                            break;
                        }
                        ans.pb(-((val.second)/j + ((val.second%j) > 0)));
                        val.second -= ((val.second)/j + ((val.second%j) > 0));
                        cnt++;
                    }
                    while(cnt < j) ans.pb(0), cnt++;
                }
                if(deu) break; 
            }
            if(deu) break;
        }
        if(!deu){
            printf("-1");
            continue;
        }
        while(ans.size() < l){
            ans.pb(-A);
        }
        reverse(all(ans));
        printf("%ld\n", ans.size());
        bool f = true;
        for(auto p: ans){
            if(!f) printf(" ");
            printf("%lld", p);
            f = false;
        }
        printf("\n");
    }
}
