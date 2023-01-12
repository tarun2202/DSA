/*	1547. Minimum Cost to Cut a Stick
	Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:
	Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
	You should perform the cuts in order, you can change the order of the cuts as you wish.
	The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
	Return the minimum total cost of the cuts.
		Input: n = 9, cuts = [5,6,1,4,2]
		Output: 22
		Explanation: If you try the given cuts ordering the cost will be 25.
		There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
*/

class Solution {
public:
    //Memorization -->TC: O(C^3)    SC: O(C^2)
    /*int f(int i, int j, vector<int> &c, vector<vector<int>> &dp){
        if(i>j) 
            return 0;

        if(dp[i][j] != -1) 
            return dp[i][j];

        long mini = INT_MAX;;
        for(int idx =i; idx<=j;idx++){
            long cost = c[j+1] - c[i-1] + f(i, idx-1, c, dp) + f(idx+1, j, c, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
        return f(1, c, cuts, dp);
    }*/

    //Tabulation--> TC: O(C^3)  SC: O(C^2)  
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));
        for(int i=c; i>=1; i--){
            for(int j=1; j<=c; j++){
                if(i>j)     continue;
                long mini = INT_MAX;
                for(int k=i; k<=j; k++){
                    int temp = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    if(temp < mini)
                        mini = temp;
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];        
    }
};
