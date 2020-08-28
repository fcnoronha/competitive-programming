#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    fastio;
    string s1, s2; cin >> s1 >> s2;
    bool ans = false;
    int n = s1.size(), m = s2.size(), i = 0, j = 0;
    while(i < n && j < m && (s1[i] < '0' || s1[i] > '9')){
        if(s1[i] > s2[j]){
            cout << ">\n"; return 0;
        }
        if(s1[i] < s2[j]){
            cout << "<\n"; return 0;
        }
        i++, j++;
    }
    if(n - i > m - j){
        cout << ">\n"; return 0;
    }
    else if(n - i < m - j){
        cout << "<\n"; return 0;
    }
    else{
        while(i < n && j < m){
            if(s1[i] > s2[j]){
                cout << ">\n"; return 0;
            }
            if(s1[i] < s2[j]){
                cout << "<\n"; return 0;
            }
            i++, j++;
        }    
    }
    cout << "=\n";
}
