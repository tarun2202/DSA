/*  Print Longest Common Subsequence
	Given the 2 string s1 and s2 of size m and n respectively. Find any one of the longest common subsequeces. 
        Input: S1 = "CBDA"   S2 = "ACADB"
        Output: "CA"

    time complexity: O(M*N) + O(M+N) + O(length of stack) ~ O(M*N)
    space complexity: O(M*N)    
*/

#include <bits/stdc++.h>
using namespace std;
void findLCS(string &s1, int m, string &s2, int n, vector<vector<int>> &dp) {
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);    
        }
    }
}
stack<char> printLongestCommonSubsequence(string &s1, string &s2){
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));    //covering the base case by initializing dp with 0.
    //finding the LCS matrix--> to backtrack our way to find the LCS string
    findLCS(s1, m, s2, n, dp);
    //storing the LCS string
    stack<char> st;
    //last index of dp matrix as per the adjusted indices of the dp matrix.
    int i=m, j=n;
    //iterate in the dp (lcs matrix)--> TC: O(M+N)
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            st.push(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--; 
        }   
        else    
            j--;
    }
    return st;
}
int main() {
    string s1, s2;
    cin>>s1>>s2;
    //empty check of input string.
    if(s1.size()==0 || s2.size()==0)
        return 0;
    stack<char> st = printLongestCommonSubsequence(s1, s2);
    // printing the content of stack.
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}

