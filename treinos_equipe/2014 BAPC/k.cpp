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

map<vi, int> M;
map<vi, int> id;
int scr[20];
string s[20];

int main(){
    int t; cin >> t;
    while(t--){
    M.clear();
    id.clear();
    int n, m; cin >> n >> m;
    fr(i, n){
        cin >> s[i];
        cin >> scr[i];
    }
    int left = m/2, right = m - m/2;
    int mid = left;
    fr(i, 1<<left){
        vi plc(n, 0);
        fr(j, left){
            if(i&(1<<j)){
                fr(k, n){
                    if(s[k][j] == '1') plc[k]++;
                }
            }
            else{
                fr(k, n){
                    if(s[k][j] == '0') plc[k]++;
                }
            }
        }
        M[plc]++;
        id[plc] = i;
    }
    int qnt = 0;
    pii ans;
    fr(i, 1<<right){
        vi plc(n);
        fr(k, n) plc[k] = scr[k];
        fr(j, right){
            if(i&(1<<j)){
                fr(k, n){
                    if(s[k][j+mid] == '1') plc[k]--;
                }
            }
            else{
                fr(k, n){
                    if(s[k][j+mid] == '0') plc[k]--;
                }
            }
        }
        if(M[plc] != 0){
            if(qnt == 0){
                ans.first = id[plc];
                ans.second = i;
            }
            qnt += M[plc];
        }
    }
        if(qnt == 1){
            fr(i, left){
                if(ans.first&(1<<i)) cout << "1";
                else cout << 0;
            }
            fr(i, right){
                if(ans.second&(1<<i)) cout << "1";
                else cout << 0;
            }
            cout << "\n";
        }
        else cout << qnt << " solutions\n";
    }
}