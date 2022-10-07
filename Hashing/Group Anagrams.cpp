/*  49. Group Anagrams
	Given an array of strings strs, group the anagrams together. You can return the answer in any order.
	An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using 
	all the original letters exactly once.
		Input: strs = ["eat","tea","tan","ate","nat","bat"]
		Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
	
	time complexity:  O(n.klogk) where k: max length of given string in vector of string (strs)
	space complexity: O(n)  	
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>>mp;
    int n=strs.size();
    for(int i=0;i<n;i++){
        string s=strs[i];
        sort(s.begin(),s.end());
        mp[s].push_back(strs[i]);
    }
    vector<vector<string>>ans;
    /*for(auto i:mp){   //this also works
        ans.push_back(i.second);
    }*/
    for(auto it=mp.begin();it!=mp.end();it++)
        ans.push_back(it->second);
    return ans;
}
int main(){
	int n;
	cin>>n;
	vector<string>strs(n);
	for(int i=0;i<n;i++)
		cin>>strs[i];
	vector<vector<string>> ans=groupAnagrams(strs);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}	
}

