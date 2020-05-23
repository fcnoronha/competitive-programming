#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
 
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
 
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const int  maxN = 1e7 + 5;

int mkd[maxN];
bool mkd2[maxN];

int size(int l, int r, int primo){
    int ans = r/primo - l/primo;
    if(l % primo == 0) ans++;
    return ans;
}

int main(){
    int n;
    int a, b;
    int c, d;
    scanf("%d %d %d %d", &a,&b,&c,&d);
    n = max(a,b);
    n = max(n,c);
    n = max(n,d);
    vector<int> caras;

    for(ll i = 2; i<=n; i++){
        if(mkd[i] == 0){ /*Primo*/
            for(ll j = i; j<=n; j += i){
                mkd[j]++;
            }
            /*Marca todos os multiplos do quadrado desse primo*/
            for(ll j = i*i; j<=n; j+= (i*i)){
                mkd2[j] = 1;
            }
        }
        if(!mkd2[i]) caras.push_back(i);
    }
    ll ans = 0;
    for(auto x : caras){
        int szA = size(a,b,x);
        int szB = size(c,d,x);
        if(mkd[x] % 2 == 0) ans -= szA*1ll*szB;
        else ans += szA*1ll*szB;
    }
    printf("%lld\n", (b-a+1) *1ll* (d-c+1) - ans);
}