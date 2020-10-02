#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i, n) for (int i = 0; i < n; i++)
#define frr(i, n) for (int i = 1; i <= n; i++)
#define ms(x, i) memset(x, i, sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define olar cout << "olar" << endl
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define int long long int
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<vector<int>, vector<int>> parzao;
const int INF = 1e18;




signed main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> items;
    vector<int> ans;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        if(x >= 0){
            items.pb(x);
        }
        else{
            int flag = 0;
            for(int j = 0; j<items.size(); j++){
                if(items[j] == -x){
                    flag = 1;
                    items[j] = -1;
                    break;
                }
            }
            if(!flag){
                for(int j = 0; j<items.size(); j++){
                    if(items[j] == 0){
                        items[j] = -1;
                        ans.pb(-x);
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    cout << "No" << endl;
                    exit(0);
                }
            }
        }

    }
    for(int j = 0; j<items.size(); j++){
        if(items[j] == 0) {
            ans.pb(1);
        }
    }
    cout << "Yes" << endl;
    for(auto y : ans){
        cout << y << " ";
    }
    cout << endl;
}