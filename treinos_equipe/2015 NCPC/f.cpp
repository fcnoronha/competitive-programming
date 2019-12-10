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

int memo[100][10001];
int f, t[10];
vi disk[10];
int curr = 0; 
int n;

int dp(int i, int l){
    if(i == n) return 1;
    if(memo[i][l] == -1){
        memo[i][l] = 0;
        if(l - disk[curr][i] >= 0) memo[i][l] |= dp(i+1, l-disk[curr][i]);
        if(l + disk[curr][i] <= t[curr]) memo[i][l] |= dp(i+1, l + disk[curr][i]);
    }
    return memo[i][l];
}

int main(){
    bool cagou = false;
    scanf("%d", &f);
    fr(i, f){
        scanf("%d", &t[i]);
        int na; scanf("%d", &na);
        fr(j, na){
            int a, b; scanf("%d%d", &a, &b);
            disk[i].push_back(b - a);
        }
        ms(memo, -1);
        curr = i;
        bool deu = false;
        n = na;
        fr(j, t[i]){
            if(dp(0, j) == 1){
                deu = true;
                break;
            }
        }
        if(!deu) cagou = true;
    }
    if(cagou) printf("impossible\n");
    else printf("possible\n");

}
