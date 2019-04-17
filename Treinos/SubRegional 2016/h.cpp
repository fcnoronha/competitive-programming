#include "bits/stdc++.h"
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

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
	string s;

	cin >> s;

	int str = 0, end = s.size() - 1;
	bool vamodale = true;

	while (str <= end){
		while (!(s[str] == 'a' || s[str] == 'e' || s[str] == 'i' || s[str] == 'o' || s[str] == 'u') && str < s.size() - 1) str++;
		while (!(s[end] == 'a' || s[end] == 'e' || s[end] == 'i' || s[end] == 'o' || s[end] == 'u') && end > 0) end--;

		if (str <= end){
			if (s[str] != s[end]) vamodale = false;
			str++; end--;
		}
	}

	(vamodale)? cout << "S" << endl : cout << "N" << endl;
}
