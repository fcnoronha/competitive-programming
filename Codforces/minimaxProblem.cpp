//codeforces.com/contest/1288/problem/D

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

#define maxn 300009

int a[maxn][8], n, m, a1, a2;

bool check(int val) {

    int aux[1<<m];
    ms(aux, -1);

    fr(i, n) {

        int mask = 0;
        fr(j, m) 
            if (a[i][j] >= val) 
                mask |= (1<<j);

        aux[mask] = i;
    }

    fr(i, 1<<m) 
        fr(j, 1<<m) { 
            if (aux[i] == -1 || aux[j] == -1) continue;
            if ((i|j) != (1<<m)-1) continue;
            a1 = aux[i];
            a2 = aux[j];
            return 1; 
        }

    return 0;
}

int main(){
    fastio;

    cin >> n >> m;
    fr(i, n) 
        fr(j, m) 
            cin >> a[i][j];

    int l = 0, r = 1000000009;
    fr(i, 40) {

        int m = (l+r)/2;
        if (check(m)) l = m+1;
        else (r = m-1);
    }

    cout << a1+1 << " " << a2+1 << endl; 
}
