#include <bits/stdc++.h>
using namespace std;

string s,t;
int xs, xt, ys, yt;
vector<string> res;

int main(){
	cin >> s >> t;

	xs = s[0] - 96;
	xt = t[0] - 96;
	ys = s[1];
	yt = t[1];

	while(xt != xs and yt != ys){
		if(xs - xt > 0) {
			if(ys - yt > 0)	{
				res.push_back("LD");
				xs -= 1;
				ys -= 1;
			}
			else{
				res.push_back("LU");
				xs -= 1;
				ys += 1;
			}

		}
		else{
			if(ys - yt > 0) {
				res.push_back("RD");
				xs += 1;
				ys -= 1;
			}
			else{
				res.push_back("RU");
				xs += 1;
				ys += 1;		
			} 		
		}
	}

	if(xt == xs){
		if(ys - yt > 0){
			for(int i = 0; i < ys-yt; i++){
				res.push_back("D");
			}
		}
		else{
			for(int i = 0; i < yt-ys; i++){
				res.push_back("U");
			}
		}
	}

	if(yt == ys){
		if(xs - xt > 0){
			for(int i = 0; i < xs-xt; i++){
				res.push_back("L");
			}
		}
		else{
			for(int i = 0; i < xt-xs; i++){
				res.push_back("R");
			}
		}
	}

	cout << res.size() << endl;

	for(int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
}