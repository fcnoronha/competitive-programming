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
    
    ll n, k, ans = 0;
    cin >> n >> k;
 
    multiset<pll> show;
    fr(i, n) {
        ll ini, fim;
        cin >> ini >> fim;
        show.insert({fim, ini});
    }
 
    multiset<ll> tape;
    fr(i, k) {
        auto oi = show.begin();
        show.erase(oi);
        tape.insert((*oi).f);
        ans++;
    }
 
    while (!show.empty()) {
        auto entra = show.begin();
        show.erase(entra);
 
        auto sai = tape.begin();
        if ((*entra).s < (*sai)) continue; 
 
        ans++;
        tape.erase(sai);
        tape.insert((*entra).f);
    }
 
    cout << ans << endl;
}
