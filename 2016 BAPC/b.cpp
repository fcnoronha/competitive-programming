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

    fastio;
    string s; cin >> s;
    string ans;

    int n = s.size();
    int ini=0;

    while(ini<n){

      if(ini+2<n){
        set<char> p;
        p.insert(s[ini]);
        p.insert(s[ini+1]);
        p.insert(s[ini+2]);
        if(p.size()==3){
          ans.pb('C');
          ini+=3;
          continue;
        }
      }

      if(s[ini]=='R')
        ans.pb('S');
      else if(s[ini]=='B')
        ans.pb('K');
      else
        ans.pb('H');
      ini++;


    }

    cout << ans << endl;


}
