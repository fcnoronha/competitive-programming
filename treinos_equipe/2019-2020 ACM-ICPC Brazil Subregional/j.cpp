#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define pb(x) push_back(x)
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()

typedef long long int ll;
const int INF =  0x3f3f3f3f;

map<int,char> id;
int freq[20][15];
bool justReceived[20];

int n,k;

int hasWon(int player){

	int mao = 0;
	for(int i=0;i<=13;i++)
		mao+=freq[player][i];
	
	if(mao!=4)
		return -1;

	for(int j=0;j<=12;j++){
		if(freq[player][j]==4)
			return player+1;
	}

	return -1;

}

int check(){
	for(int i=0;i<n;i++)
		if(hasWon(i)!=-1)
			return i+1;
	return -1;
}

void play(int player){

	int prox = (player+1)%n;

	int passa=-1;
	int best=INF;

	for(int i=0;i<13;i++){
		if(freq[player][i]<best && freq[player][i]!=0){
			best=freq[player][i];
			passa=i;
		}
	}

	if(freq[player][13] && justReceived[player]==false)
		passa=13;

	if(passa==13){
		justReceived[prox]=true;
	}

	justReceived[player]=false;

	freq[prox][passa]++;

	freq[player][passa]--;

}

int main() {

	fastio;

	id['A']=0;
	id['2']=1;
	id['3']=2;
	id['4']=3;
	id['5']=4;
	id['6']=5;
	id['7']=6;
	id['8']=7;
	id['9']=8;
	id['D']=9;
	id['Q']=10;
	id['J']=11;
	id['K']=12;
	//joker
	id['#']=13;

	cin >> n >> k;
	string s;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,4){
			freq[i][ id[s[j]] ]++;
		}
	}

	freq[k-1][13]++;
	justReceived[k-1]=true;

	int player = k-1;

	while(check()==-1){
		play(player);
		player=(player+1)%n;
		if(check()!=-1)	break;
	}

	cout << check() << endl;

}