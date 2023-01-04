/*	354. Russian Doll Envelopes
	You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of 
	an envelope.
	One envelope can fit into another if and only if both the width and height of one envelope are greater than the 
	other envelope's width and height.
	Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
	Note: You cannot rotate an envelope.
		Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
		Output: 3
		Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
	
	time complexity: O()
	space complexity: O()	
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int N = envelopes.size();
        if (N == 0)
            return N;
        // Sort the envelopes in non-decreasing order
        sort(envelopes.begin(), envelopes.end());
        // Initialize dp[] array
        int dp[N];
        // To store the result
        int max_envelope = 1;
        dp[0] = 1;
 
        // Loop through the array
        for (int i = 1; i < N; ++i) {
            dp[i] = 1;
            // Find envelopes count for each envelope
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]
                        && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
            // Store maximum envelopes count
            max_envelope = max(max_envelope, dp[i]);
        }
        // Return the result
        return max_envelope;
    }
};
