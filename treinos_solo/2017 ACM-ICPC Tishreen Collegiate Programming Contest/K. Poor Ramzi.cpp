#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x);
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
const int MOD = 1000000007;

int arr[55];
int memo[55][55];

int pd(int l, int r) {

    if (l >= r) return 1;

	int &pdm = memo[l][r];
	if (~pdm) return pdm;
    pdm = 1;

    int l_sum = 0;
    for (int i = l; i < r; i++) {

        l_sum += arr[i];
        int r_sum = 0;

        for (int j = r; j > i; j--) {
            r_sum += arr[j];
            if (r_sum > l_sum) break;
            if (r_sum == l_sum) pdm += pd(i+1, j-1);
            pdm %= MOD;
        }
    }

    return pdm;
}

int main(){

	int t; cin >> t;
	while(t--){

		string s;
        cin >> s;
		int m = s.size();

		fr(i, m)
			arr[i] = (s[i] - '0');

        ms(memo, -1);

		cout << pd(0, m-1) << endl;
	}
}
