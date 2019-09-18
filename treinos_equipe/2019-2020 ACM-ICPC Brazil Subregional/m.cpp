#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,n)	for(int i=0;i<n;i++)
#define dbg(x)	cout << #x << " = " << x << endl
#define frr(i,n) for(int i=1;i<=n;i++)

typedef long long int ll;
const int INF =  0x3f3f3f3f;

ll n,c,t;
ll v[100100];
ll sum;
// bb no tempo
bool check(ll val){

	ll caras = c;
	
	//comeca balde 1 pipoca
	int ini=1;

	//total de pipocas no blade
	ll sobra=sum;

	//quanto cada um come
	ll podecomer = val*t;

	for(int i=1;i<=c;i++){
		
		if(ini>n)
			break;
		
		ll tenho =0;
		
		while(ini<=n && tenho+v[ini]<=podecomer){
			tenho+=v[ini];
			sobra-=v[ini];
			ini++;
		}
	
	}

	return sobra==0;

}

int main(){

	fastio;

	cin >> n >> c >> t;

	frr(i,n){
		cin >> v[i];
		sum+=v[i];
	}


	ll ini=1;
	ll end=1e11;
	ll best = INF;

	while(ini<=end){
		ll mid = (ini+end)>>1;
		if(check(mid)){
			best=mid;
			end=mid-1;
		}
		else
			ini=mid+1;
	}
	cout << best << endl;
}