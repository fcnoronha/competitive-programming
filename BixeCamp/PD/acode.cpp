#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string s;
int a1, a2, r;

int main(){
	cin >> s;

	while(s != "0"){
		r = a1 = a2 = 1;
		for(int i = 0; i < s.size(); i++){
			int ant = s[i-1] - '0';
			int atual = s[i] - '0';

			if(r == 0){
				a1 = a2 = r;
			}

			if(atual == 0){
				if(ant == 0){
					r = 0;
				}
				else if(ant > 2){
					r = 0;
				}
				else if(a2 != a1){
					r = a1 = a2;
				}
				else{
					r = r;
				}
			}

			else if(ant*10 + atual > 0 and ant*10 + atual < 27 and ant != 0){
				r = a1 + a2;
				a2 = a1;
				a1 = r;
			}	

			else{
				a2 = a1;
				a1 = r;
			}
		}
		cout << r << endl;
		cin >> s;
	}
} 