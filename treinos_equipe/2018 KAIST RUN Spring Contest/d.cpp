#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 112345

string alpha[] = {"New Customer" // 0
, "Promising"                    // 1   
, "About to Sleep"               // 2
, "Hibernating"                  // 3
, "Lost"                         // 4
, "Potential Loyalist"           // 5
, "Need Attention"               // 6
, "About to Leave"               // 7
, "Champion"                     // 8
, "Loyal Customer"               // 9
, "Can't Lose Them"};            // 10

int val[5][5] = {{0, 1, 2, 4, 4 },
                 {5, 5, 2, 3, 4 }, 
                 {5, 5, 6, 7, 7 },
                 {9, 9, 9, 7, 7 },
                 {8, 9, 9, 7, 10}};

int lst[maxn], amt[maxn];
map<string, int> mp;
int id = 1;

int main(){
    fastio;

    int r[5], f[5];
    fr(i, 4) cin >> r[i];
    fr(i, 4) cin >> f[i];

    r[4] = INF, f[4] = INF;

    int n;
    cin >> n;
    
    frr(ct, n) {
    
        int A;
        string B;
        cin >> A >> B;
    
        if (mp.find(B) == mp.end()) 
            mp[B] = id++;
    
        int i = mp[B];
        if (A == 1) {
            amt[i]++;
            lst[i] = ct;
            continue;
        }
        if (A == 2 && amt[i] == 0){
            cout << "None\n";
            continue;
        }

        int ri = 0, fi = 0;
        while (ct-lst[i] > r[ri]) ri++;
        while (amt[i] > f[fi]) fi++;

        cout << alpha[val[fi][ri]] << "\n"; 
        continue;
    }
}