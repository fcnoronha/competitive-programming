//codeforces.com/gym/101047

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

int main(){
    fastio

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi ok;
        if(n == 0){
            for(int i = 2; i <= 16; i++){
                cout << i << " \n"[i == 16];
            }
            continue;
        }
        for(int i = 2; i <= 16; i++){
            vi ans;
            int cop = n;
            while(cop != 0){
                ans.pb(cop%i);
                cop /= i;
            }
            int j = 0, k = ans.size() - 1;
            bool consegui = true;
            while(j < k){
                if(ans[j] != ans[k]) consegui = false;
                j++;
                k--;
            }
            if(consegui) ok.pb(i);
        }
        bool first = true;
        for(int a: ok){
            if(!first) cout << " ";
            first = false;
            cout << a;
        }
        if(ok.empty()) cout << "-1";
        cout << endl;
    }
}
