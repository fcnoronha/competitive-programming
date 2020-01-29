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

int main(){
    fastio;
    int n; cin >> n;
    fr(i, n){
        string s; cin >> s;
        int sz = s.size();
        int pos = sz - 1; 
        if(s[pos] == 'a'){
            s.append("s");
        }
        else if(s[pos] == 'i' || s[pos] == 'y'){
            s.pop_back();
            s.append("ios");
        }
        else if(s[pos] == 'l'){
            s.append("es");
        }
        else if(s[pos] == 'n'){
            s.pop_back();
            s.append("anes");
        }
        else if((sz > 2 && s[pos] == 'e' && s[pos-1] == 'n')){
            s.pop_back();
            s.pop_back();
            s.append("anes");
        }
        else if(s[pos] == 'o'){
            s.append("s");
        }
        else if(s[pos] == 'r'){
            s.append("es");
        }
        else if(s[pos] == 't'){
            s.append("as");
        }
        else if(s[pos] == 'u'){
            s.append("s");
        }
        else if(s[pos] == 'v'){
            s.append("es");
        }
        else if(s[pos] == 'w'){
            s.append("as");
        }
        else s.append("us");
        cout << s << endl;
    }
}
