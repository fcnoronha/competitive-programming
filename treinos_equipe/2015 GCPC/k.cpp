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

    string s;
    cin >> s;

    for(auto x : s){
        if(x=='3' || x=='4' || x=='7'){
            cout << "no" << endl;
            return 0;
        }
    }

    ll aux = stoll(s);

    for(ll i = 2;i*i<=aux;i++){
        if(aux%i==0){
            cout << "no" << endl;
            return 0;
        }
    }

    reverse(all(s));
    string ans;
    for(auto x : s){
        if(x=='6')
            ans.pb('9');
        else if(x=='9')
            ans.pb('6');
        else
            ans.pb(x);
    }

    ll go = stoll(ans);

    if(go==1){
        cout << "no" << endl;
        return 0;
    }

    for(ll i = 2;i*i<=go;i++){
        if(go%i==0){
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;

}