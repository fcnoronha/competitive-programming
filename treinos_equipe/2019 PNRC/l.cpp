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


int a[100100];
int b[100100];

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    
    int ans = -1;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            if(i >= a[j] && i <= b[j]) cnt++;
        }
        if(cnt == i) ans = max(ans, i);
    }
    printf("%d\n",ans);
}