// https://www.urionlinejudge.com.br/judge/en/problems/origin/125

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
    
    int a,b,c;
    
    cin >> a >> b >> c;

    if(a-b==0)
    	cout << "S" << endl;
    else if(a-c==0)
    	cout << "S" << endl;
    else if(b-c==0)
    	cout << "S" << endl;
    else if(a-(b+c)==0)
    	cout << "S" << endl;
    else if(b-(a+c)==0)
    	cout << "S" << endl;
    else if(c-(a+b)==0)
    	cout << "S" << endl;
    else
    	cout << "N" << endl;



}
