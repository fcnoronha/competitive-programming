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

int main(){
    rvr(n);
    vii vec(n);
    fr(i, n){
        scanf("%d%d", &vec[i].fst, &vec[i].snd);
    }
    int ans = 1;
    int l = 2, r = n;
    set<pii> S, F;
    while(l <= r){
        int mid = (l+r)/2;
        S.clear(), F.clear();
        fr(i, mid){
            S.insert(mp(-vec[i].first, i));
            F.insert(mp(vec[i].snd, i));
        }
        bool deu = false;
        if(mid == n){
            if((*F.begin()).first + (*S.begin()).first + 1 >= mid){
                deu = true;
                
            }
        }
        for(int j = mid; j < n; j++){
            if((*F.begin()).first + (*S.begin()).first + 1 >= mid){
                deu = true;
                break;
            }
            S.erase(mp(-vec[j - mid].first, j-mid));
            F.erase(mp(vec[j - mid].snd, j-mid));
            S.insert(mp(-vec[j].fst, j));
            F.insert(mp(vec[j].snd, j));
            if((*F.begin()).first + (*S.begin()).first + 1 >= mid){
                deu = true;
                break;
            }
        }
        if(deu){
            ans = max(ans, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%d\n", ans);
}
