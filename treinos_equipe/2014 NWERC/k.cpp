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
const int N = 2e3 + 1;

int n, s, t;
int k[N];

int main(){
    scanf("%d%d%d", &n, &s, &t);
    fr(i, n){
        scanf("%d", &k[i]);
    }
    ll mx = -1, mn = LLONG_MAX;
    multiset<int> M;
    vector<pair<int, ll>> vec(n);
    fr(i, n){
        fr(j, n){
            if(j != i) M.insert(k[j]);
        }
        ll ans = 0;
        int time = k[i];
        while(!M.empty()){
            int vaca = (time+t)%s;
            auto it = M.lower_bound(vaca);
            if(it == M.end()){
                it = M.begin();
            }
            int nxt = *it;
            //printf("i %d tam %d nxt %d\n", i, (int) M.size(), nxt);
            if(vaca <= nxt){
               ans += (ll) (t + nxt - vaca); 
            }
            else{
                ans += (ll)(t + s - vaca + nxt);
            }
            time = nxt;
            M.erase(it);
            //printf("i %d tam %d ans %lld\n", i, (int) M.size(), ans);
        }
        ans += (ll) t;
        mx = max(mx, ans);
        mn = min(mn, ans);
        vec[i] = mp(k[i], ans);
        M.clear();
    }
    sort(all(vec));
    ll sm = 0;
    int nxt = 0;
    fr(i, s){
        ll vaca;
        if(nxt == n){
            vaca = ((ll) (s - i) + (ll)vec[0].ff) + vec[0].ss;
        }
        else{
            while(nxt < n && vec[nxt].ff < i) nxt++;
            if(nxt == n){
                vaca = (ll)((ll) (s - i) + (ll)vec[0].ff) + vec[0].ss;
            }
            else{
                vaca = ((ll) (vec[nxt].ff - i) + vec[nxt].ss);
            }
        }
        sm += vaca;
        mn = min(vaca, mn);
        mx = max(vaca, mx);
    }
    printf("%lld\n%lld\n%lld/%lld\n", mn, mx, sm/__gcd(sm, (ll)s), s/__gcd(sm, (ll)s));
}