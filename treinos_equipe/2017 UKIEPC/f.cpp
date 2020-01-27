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

double pd[401][401][401];

double solve(int A, int B, int K){
    if(K == 0) return A;
    if(pd[A][B][K] >= 0.0) return pd[A][B][K];
    if(B>0){
        return pd[A][B][K] = 0.5*(solve(A+1,B-1,K-1)) + 0.5*(solve(A,B,K-1));
    }
    else{
        return pd[A][B][K] = 0.5*(solve(A,B,K-1)) + 0.5*(solve(A-1,B+1,K-1));
    } 
}


int main(){
    fastio;
    for(int i = 0; i<=400; i++){
        for(int j = 0; j<=400; j++){
            for(int k = 0; k<=400; k++){
                pd[i][j][k] = -1.0;
            }
        }
    }
    int B,K;
    cin >> B >> K;
    cout << fixed;
    cout << setprecision(7);
    cout << solve(0,B,K) << endl;
}
