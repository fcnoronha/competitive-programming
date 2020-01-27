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


map<string, int> M;

int main(){
    int n; cin >> n;
    int rd = 0;
    int mx = 0, sm = 0;
    M["black"] = 7;
    M["pink"] = 6;
    M["blue"] = 5;
    M["brown"] = 4;
    M["green"] = 3;
    M["yellow"] = 2;
    fr(i, n){
        string s; cin >> s;
        if(s != "red") mx = max(M[s], mx), sm += M[s];
        else rd++, sm++;
    }
    sm += rd*mx;
    if(rd == n) sm = 1;
    printf("%d\n", sm);
}
