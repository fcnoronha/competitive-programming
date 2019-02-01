#include<bits/stdc++.h>
using namespace std;

// Store and check for strings

#define MAXN 10019 

struct t {

	bool isWordEnd;
	int lts[26]; // 0 - position 'a'

} trie[MAXN];

int cnt = 1; // Latest node - trie[0] == root

void add(string str, int idx, int node){

	// If its already in the end
	if (str.length() == idx){
		trie[node].isWordEnd = true;
		return;
	}

	int &lidx = trie[node].lts[ str[idx]-'a' ];
	// If there is no following to that letter
	if (lidx == -1){

		lidx = cnt;

		trie[cnt].isWordEnd = false;
		for (int l = 0; l <= 25; l++)
			trie[cnt].lts[l] = -1;

		cnt++;
		add(str, idx+1, cnt-1);
	}

	// Otherwise, continues add
	else 
		add(str, idx+1, lidx);
}

bool search(string str, int idx, int node){

	// Found
	if (idx == str.length())
		return true;

	int &lidx = trie[node].lts[ str[idx]-'a' ];
	// Not found
	if (lidx == -1)
		return false;

	return search(str, idx+1, lidx);
}
	
int main(){

	// Initializing root
	for (int i = 0; i < 26; i++)
		trie[0].lts[i] = -1;

	add("felipe", 0, 0);

	cout << search("k", 0, 0) << endl;

}