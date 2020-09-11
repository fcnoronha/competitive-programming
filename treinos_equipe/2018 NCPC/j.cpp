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

int root(int a){
    for(int k = 1;;k++){
        if((k*(k+1))/2 == a) return k+1;
        if((k*(k+1))/2 > a) return -1;
    }
}

int main(){
    int a, b, c, d; scanf("%d%d%d%d", &a, &d, &c, &b);
    if(a == 0 && b == 0 && c == 0 && d == 0){
        printf("0\n");
        return 0;
    }
    if(a == 0 && b == 0 && c == 1 && d == 0){
        printf("10\n");
        return 0;
    }
    if(a == 0 && b == 0 && c == 0 && d == 1){
        printf("01\n");
        return 0;
    }
    bool chgb = false, chga = false;
    if(root(a) == -1 || root(b) == -1 || (c+d) != (root(a)*root(b))){
        if(root(a) > 0 && b == 0 && ((d + c == root(a)) ||(c == 0 && d == 0))){
            if(c + d == root(a)){
                b = 1;
                chgb = true;
            }
            goto GO;
        }
        if(a == 0 && root(b) > 0 && ((d + c == root(b))|| (c == 0 && d == 0))){
            if((d + c) == root(b)){
                a = 1;
                chga = true;
            }
            
            goto GO;
        }
        printf("impossible\n");
        return 0;
    }
    GO:
    if(!chga) a = root(a); 
    if(!chgb) b = root(b);
    string ans;
    fr(i, a) ans.pb('0');
    fr(i, b) ans.pb('1');
    int l0 = 0, l1 = a;
    while(c){
        if(l1 - l0 <= c){
            swap(ans[l0], ans[l1]);
            c -= (l1 - l0);
            l0++;
            l1++;
        }
        else{
            swap(ans[l1 - c], ans[l1]);
            c = 0;
        }
    }
    printf("%s\n", ans.c_str());


}
