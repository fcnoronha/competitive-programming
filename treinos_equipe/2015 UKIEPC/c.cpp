#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

const int N = 2e6+100;

int m;

map<string, int> mpu, mpm;
set<int> st[N];
vector<string> msg;
int freq[N];

vector< pair<int, string> > ans;

char stra[100];

int main(){

	scanf("%d ", &m);

	fr(i, m){

		scanf("%s ", stra);

		string usr(stra);

		int id;
		if (!mpu.count(usr)){
			id = mpu.size();
			mpu[usr] = mpu.size();
		}
		else {
			id = mpu[usr];
		}

		char c = 0;
		string aux = "";
		scanf(" ");

		while (c != '\n'){

			while (scanf("%c", &c) != EOF && !isspace(c))
				aux += c;

			int id2;
			if (!mpm.count(aux)){
				id2 = mpm.size();
				mpm[aux] = id2;

				msg.pb(aux);
			}
			else {
				id2 = mpm[aux];
			}

			freq[id2]++;
			st[id2].insert(id);

			aux = "";
		}
	}

	fr(i, msg.size()){

		if (st[i].size() == mpu.size())
			ans.pb({-freq[i], msg[i]});

	}

	sort(all(ans));

	if (ans.size() == 0){
		p(ALL CLEAR);
		return 0;
	}

	for (auto m : ans)
		cout << (m).s << endl;
}
