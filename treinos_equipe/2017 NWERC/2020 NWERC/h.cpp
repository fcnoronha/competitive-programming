#include <bits/stdc++.h>
using namespace std;
     
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;


#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args);
#endif

#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int v[200200];
int ans[200200];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i =0;i<n;i++){
        cin >> v[i];
    }
    sort(v,v+n);
    ans[n-1] = v[n-1];
    ans[n-2] = v[0];
    int p = 1;
    int r = n-2;
    int f = 1;
    int t = n-3;
    while (p <= r) {
        if ( f==0) {
            ans[t--] = v[p];
            p++;
        }
        else {
            ans[t--] = v[r];
            r--;
        }
        f = (f+1)%2;
    }
    for (int i = 0; i<n; i++) cout << ans[i] << " ";
    cout << endl;

}
