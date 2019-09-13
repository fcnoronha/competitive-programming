#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

bool vis[1100100];
vector<ll> primes;

int main(){

    fastio;
    ll n;cin>>n;

    if (n == 1){
      cout<<"no"<<endl;
      return 0;
    }

    for(ll i=2;i<=1000000;i++){
      if(!vis[i]){
        vis[i]=true;
        primes.pb(i);
        for(ll j=i;j<=1000000;j+=i)
          vis[j]=true;
      }
    }

    bool isPrime=true;
    for(ll i=2;i<=1000000;i++){
      if(n%i==0)
        isPrime=false;
    }

    if(isPrime){
      cout << "yes" << endl;
      return 0;
    }

    int cnt=0;

    for(auto x : primes)
      if(n%x==0){
        cnt++;
        while(n%x==0)
          n/=x;
      }

    if(cnt==1 && n==1)
      cout << "yes" << endl;
    else
      cout << "no" << endl;

}
