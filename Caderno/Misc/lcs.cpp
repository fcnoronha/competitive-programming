// LCS - LONGEST COMMON SUBSEQUENCE

// Given a sequence s1 and s2, finds the longest common subsequence to s1 and s2

// O(a*b), sizes of sequences

#define MAXN 1009;

int dp[MAXN][MAXN];
vi s1;
vi s2;
vi glcs; // Used if wnat to print

int lcs(int a, int b){
	// 'a' == a-th element of s1
	// 'b' == b-th element of s2
	// LCS until those bounderyes
 	
	for (int i = 0; i <= a; i++){
		for (int j = 0; j <= b; j++){

			// If one of sequences is empty
			if (!i || !j) dp[i][j] = 0;

			// If they are equal, eliminate both
			else if (s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];

			// Gets maximum between take off one or another
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[a][b];
}

void getLcs(int a, int b){
	// Stores LCS at glcs

	while (a > 0 && b > 0){

		// if s1[a] == s2[b] then they are part of LCS
		if (s1[a-1] == s2[b-1]){
			glcs.pb(s1[a-1])
			a--; b--;
		}

		// Going to the larger value
		else if (dp[a-1][b] > dp[a][b-1])
			a--;
		else 
			b--;
	}	

	// It was made bottom-up
	reverse(glcs.begin(), glcs.end());
}

int main(){

	// Way to call it
	int ans = lcs(s1.size(), s2.size());

	// Way to call it
	getLcs(s1.size(), s2.size());

}