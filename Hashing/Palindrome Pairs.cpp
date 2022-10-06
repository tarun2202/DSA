/*	336. Palindrome Pairs
	You are given a 0-indexed array of unique strings words.
	A palindrome pair is a pair of integers (i, j) such that:
		0 <= i, j < word.length, i != j, and words[i] + words[j] (the concatenation of the two strings) is a palindrome string.
	Return an array of all the palindrome pairs of words.
	
		Input: words = ["abcd","dcba","lls","s","sssll"]
		Output: [[0,1],[1,0],[3,2],[2,4]]
		Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
		
	naive approach--> 	  TC: O(n^2.k)	 	
	optimised Approach--> TC: O(n.k^2)	
*/

#include <bits/stdc++.h>
using namespace std;

//naive approach:
/*vector<vector<int>>ans;
bool checkPalindrome(string s){
	int l=s.length();
    for(int i=0;i<l/2;i++)
		if(s[i]!=s[l-i-1])
			return false;
	return true;
}
vector<vector<int>> findPalindromePairs(vector<string>&words){
	int n=words.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j && checkPalindrome(words[i]+words[j]))
				ans.push_back({i,j});
		}
	}		
}*/

//optmised approach
bool isPalindrome(string s,int i,int j){
	while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;j--;
    }
    return true;
} 
vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>>ans;
    unordered_map<string,int>umap;
    for(int i=0;i<words.size();i++)
        umap[string(words[i].rbegin(),words[i].rend())]=i;
    map<pair<int,int>,bool>m;
    for(int i=0;i<words.size();i++){
        if(umap.find("")!=umap.end() && umap[""]!=i && isPalindrome(words[i],0,words[i].size()-1) && m.find({i,umap[""]})==m.end()){
            m[{i,umap[""]}]=true;
            m[{umap[""],i}]=true;
            ans.push_back({i,umap[""]});
            ans.push_back({umap[""],i});
        }
        string prefix;
        for(int j=0;j<words[i].length();j++){
            prefix=words[i].substr(0,j+1);
            if(umap.find(prefix)!=umap.end() && umap[prefix]!=i && isPalindrome(words[i],j+1, words[i].size()-1) && m.find({i,umap[prefix]})==m.end()){
                m[{i,umap[prefix]}]=true;
                ans.push_back({i,umap[prefix]});
            }
        }
        string suffix;
        for(int j=words[i].length()-1;j>=0;j--){
            suffix=words[i].substr(j,words[i].length()-1);
            if(umap.find(suffix)!=umap.end() && umap[suffix]!=i && isPalindrome(words[i],0,j-1) && m.find({umap[suffix],i})==m.end()){
                m[{umap[suffix],i}]=true;
                ans.push_back({umap[suffix],i});
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<string>words(n);
    for(int i=0;i<n;i++)
        cin>>words[i];
    ans= findPalindromePairs(words);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }    
}

