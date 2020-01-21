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
const int N = 2e5 + 1;

int suf[N];


int main(){
    fastio;
    ms(suf, INF);
    string s;
    cin >> s;
    int n; cin >> n;
    int ori = s.size();
    fr(i, ori) s.push_back(s[i]);
    int sz = s.size();
    for(int i = sz - 1; i >= 0; i--){
        if(s[i] == 'E') suf[i] = i;
        else if(i < sz - 1) suf[i] = min(suf[i], suf[i+1]);
    }
    ll ans = 0;
    fr(i, ori){
        if(s[i] == 'E') ans += (ll)n;
        else{
            if(abs(suf[i] - i + 1) > n) continue;
            else ans += (ll)n - (ll)abs(suf[i] - i + 1) + 1ll;
        }
    }
    cout << ans << endl;
}