//codeforces.com/contest/1195/problem/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int freq[1004];

int main(){
	fastio

    int n, k;
    cin >> n >> k;

    int x;
    fr(i, n) {
        cin >> x;
        freq[x]++;
    }

    int ans = 0, rm = 0;
    frr(i, k)
        ans += freq[i]/2, rm += freq[i]%2;

    rm++;
    rm /= 2;

    p(ans*2 + rm);
}
