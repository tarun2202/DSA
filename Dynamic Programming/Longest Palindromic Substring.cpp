/*	5. Longest Palindromic Substring
	Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 
	0 = i = j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if 
	reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).
		Input: s = "babad"
		Output: "bab"
		Explanation: "aba" is also a valid answer.
	
	time complexity: O(m*m)
	space complexity: O()	
*/

class Solution{   
public:
    //Naive approach: TC: O(N^3)    SC: O(1)   
    /*string longestPalindrome(string str){
        int n = str.size();
        // All substrings of length 1 are palindromes
        int maxLength = 1, start = 0;
        // Nested loop to mark start and end index of substring
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                //considering current substring is palindrome
                int flag = 1;
                // check if current substring is palindrome or not
                for (int k=0; k<(j - i + 1)/2; k++)
                    if (str[i+k] != str[j-k])
                        flag = 0;
                // current substring is palindrome
                if (flag && (j-i+1) > maxLength) {
                    start = i;
                    maxLength = j-i+1;
                }
            }
        }
        string ans;
        for (int i=start; i<=start+maxLength-1; i++)
            ans += str[i];
        return ans;
    }*/
        
    // DP Approach [Bottom Up DP]
    string longestPalindrome(string str){
        // get length of input string
        int n = str.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, true));
        // Check for substrings of lengths [1,2...n-1] 
        for (int d=1; d<n; d++) {
            int i=0, j=d;
            while(i<n && j<n){
                isPal[i][j] = isPal[i+1][j-1] && str[i]==str[j];
                i++; 
                j++;
            }
        }
        //All substrings of length 1 are palindromes
        int start=0, end=0, maxLength=1;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPal[i][j] && j-i+1 > maxLength)
                    start=i, end=j, maxLength=j-i+1;
            }
        }
        string ans="";
        for (int i=start; i<=start+maxLength-1; i++)
            ans += str[i];
        return ans;
    }
};
