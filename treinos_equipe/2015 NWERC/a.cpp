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
    rvr(m);
    multiset<pii> q;
    fr(i, n){
        rvr(a);
        rvr(b);
        q.insert(mp(a, 1));
        q.insert(mp(a+b, 0));
    }
    int qnt = 0, id = 3;
    set<pii> av;
    while(!q.empty()){
        pii cur = *q.begin();
        //printf("ff %d ss %d\n", cur.ff, cur.ss);
        q.erase(q.begin());
        if(cur.ss == 1){
            if(!av.empty()){
                q.erase(*av.begin());
                av.erase(av.begin());
            }
            else{
                qnt++;
            }
        }
        else if(cur.ss == 0){
            av.insert(mp(cur.ff+m, id));
            q.insert(mp(cur.ff+m, id++));
        }
        else{
            av.erase(cur);
        }
    }
    printf("%d\n", n - qnt);
}