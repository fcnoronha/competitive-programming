// LCS - LONGEST COMMON SUBSEQUENCE
// Given a sequence s1 and s2, finds the longest common subsequence to s1 and s2
// O(a*b), sizes of sequences

#define MAXN 1009

int dp[MAXN][MAXN];
vi s1, s2;

int lcs(string s1, string s2){
	int a = s1.size(), b = s2.size();

	for (int i = 0; i <= a; i++){
		for (int j = 0; j <= b; j++){
			if (!i || !j) dp[i][j] = 0;
			else if (s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[a][b];
}

string getLcs(string s1, string s2){
	int a = s1.size(), b = s2.size();
	string ans;
	while (a > 0 && b > 0){
		if (s1[a-1] == s2[b-1]){
			ans += s1[a-1];
			a--; b--;
		}
		else if (dp[a-1][b] > dp[a][b-1])
			a--;
		else 
			b--;
	}	
	reverse(ans.begin(), ans.end());
	return ans;
}