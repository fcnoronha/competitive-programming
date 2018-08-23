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
#define otp(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int mx = -INF, mn = INF, N;
ll tot; 
string list[0x3f];
int memo[67000];



int remove(int bit_value, string value){
	vector<char> num;
	fr(i, 15){
		if(bit_value%2){
			if(i < 10) num.pb('0' + i);
			else num.pb('a' + i - 10);
		}
		bit_value = bit_value/2;
	}
	vector<char> out;
	for(char z: value){
		bool tem = false;
		for(char x: num){
			if(x == z) tem = true;   
		}
		if(!tem) out.pb(z);
	}
	int sum = 0, aux = 1;
	for(int i = out.size() - 1; i >= 0; i--){
		if(isalpha(out[i])) sum += (out[i] - 'a' + 10)*aux;
		else sum += (out[i] - '0')*aux;
		aux = aux*16;
	}
	return sum;	
}

int sum(int bit_value){
	if(memo[bit_value] == -1){
		memo[bit_value] = 0;
		fr(i, N) memo[bit_value] += remove(bit_value, list[i]);
	}
	return memo[bit_value];
}

int permutations(){
	
}


int main(){



}