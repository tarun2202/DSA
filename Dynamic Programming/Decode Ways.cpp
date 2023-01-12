/*	91. Decode Ways
	A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:
	'A' -> 1
	'B' -> 2
	...
	'Z' -> 26
	You are an FBI agent. You have to determine the total number of ways that message can be decoded.
*/

class Solution {
public:
	//Memorization --> tc: o(n)		sc: o(n)
    /*bool isValid(int code, int len){
	        if(len==1)
	            return (code>=1 && code<=9);
	        return code>=10 && code<=26 ;     
	}
	int countDecoding(int i, string &s, vector<int> &dp){
	        if(i >= s.length())
	            return 1;
	        if(dp[i]!=-1)
	            return dp[i];
	        int ans = 0;
	        if(isValid(s[i]-'0', 1))
	            ans += countDecoding(i+1, s, dp);
	        if(i < s.size()-1 && isValid((s[i] - '0')*10 + s[i+1]-'0', 2))
	            ans += countDecoding(i+2, s, dp);
	        return dp[i] = ans;     
	}
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return countDecoding(0, s, dp);
    }*/

    //Tabulation--> TC: O(N)    SC: O(N)
    /*bool isValid(int code, int len){
	    if(len==1)
	        return (code>=1 && code<=9);
	    return code>=10 && code<=26 ;     
	}
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
		dp[0]= isValid(s[0]-'0', 1) ? 1 : 0;
		if(s.length()==1)
		    return dp[0];
		dp[1]=0;
		if(isValid(s[1]-'0', 1))
		    dp[1] += dp[0]; 
		    
		if(isValid((s[0]-'0')*10 + s[1]-'0', 2))
		    dp[1]++;
		  
		for(int i=2; i<n; i++){
		    dp[i] = 0;
		    if(isValid(s[i]-'0', 1))
		        dp[i] += dp[i-1];
		    if(isValid((s[i-1]-'0')*10 + s[i]-'0', 2))
		        dp[i] += dp[i-2];
		}
		return dp[n-1];
    }*/

    //Space Optimization
    bool isValid(int code, int len){
	    if(len==1)
	        return (code>=1 && code<=9);
	    return code>=10 && code<=26 ;     
	}
    int numDecodings(string s) {
        int n=s.size();
		vector<int> dp(n, 0);
		int first= isValid(s[0]-'0', 1) ? 1 : 0;
		if(s.length()==1)
		    return first;
		int second = 0;
		if(isValid(s[1]-'0', 1))
		    second += first; 
		     
		if(isValid((s[0]-'0')*10 + s[1]-'0', 2))
		    second++;
		  
		int third;
		for(int i=2; i<n; i++){
		    third = 0;
		    if(isValid(s[i]-'0', 1))
		        third += second;
		    if(isValid((s[i-1]-'0')*10 + s[i]-'0', 2))
		        third += first;
		    first = second;
		    second= third;
		}
		return second;
    }
};
