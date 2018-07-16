// http://codeforces.com/contest/665/problem/C

#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	cin >> s;
	s += " ";

	string letras = "abcdefghijklmnopqrstuvwxyz";

	for(int i = 1; i < s.size()-1; i++){
        if (s[i]==s[i-1]){
            int x = 0;
            while (letras[x] == s[i-1] || letras[x] == s[i+1]){
                x++;
            }
            s[i] = letras[x];
        }
    }
    cout << s << endl;
}