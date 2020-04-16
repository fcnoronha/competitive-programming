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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    fastio;

    ll n;
    cin >> n;
    ll v[1000000];
    frr(i,n){
        cin >> v[i];
    }

    ll sum = 0ll;

    frr(i,n){
        if(i%2 == n%2) sum += v[i];
        else sum -= v[i];
    }

    int q;
    cin >> q;
    fr(i,q){
        ll l,r,c;
        cin >> l >> r >> c;

        if((r - l  + 1)%2 == 0){
            cout << sum <<"\n";
            
        }
        else{
            if(r%2 == n%2) sum += c;
            else sum -= c;

            cout << sum << "\n";
        }
    }
}

