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

bool arr[112345];

int main(){
    fastio;
    int t; cin >> t;
    while(t--){

        int n; cin >> n;

        frr(i, n){
            char a; cin >> a;
            arr[i] = a == 'D';
        }

        bool consegui = true;
        vi ans;
        int i = 1;
        while(i <= n){
            bool curr = arr[i];
            stack<int> plc;
            while(!curr){
                plc.push(i);
                i++;
                if(i > n){
                    consegui = false;
                    break;
                }
                curr = arr[i];
            }
            ans.pb(i);
            while(!plc.empty()){
                int pk = plc.top();
                plc.pop();
                ans.pb(pk);
            }
            if(!consegui) break;
            i++;
            if(i <= n) arr[i] = !arr[i];
        }

        if(!consegui){
            cout << "N\n";
            continue;
        }
        cout << "Y\n";
        fr(i, n){
            cout << ans[i] << " \n"[i==n-1];
        }

    }
}
