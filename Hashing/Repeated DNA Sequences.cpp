/*	187. Repeated DNA Sequences
	Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur 
	more than once in a DNA molecule. You may return the answer in any order.
		Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
		Output: ["AAAAACCCCC","CCCCCAAAAA"]
		
	time complexity: O(n)
	space complexity: O(n)	
*/

#include<bits/stdc++.h>
using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
	vector<string>ans;
	if(s.size()<10)
		return ans;
	unordered_map<string,int> m;
	//populating hashmap with all substrings of size 10 along with its occurence in input string
	for(int i=0;i<s.length()-9;i++)
		m[s.substr(i,10)]++;
	//checking in hashmap for the sequence which occurs more than once	
	for(auto it=m.begin();it!=m.end();it++)
		if(it->second>1)
			ans.push_back(it->first);	//putting the valid substring (of size 10, which occurs more than once) in ans. 
	return ans;
}
int main(){
	string s;
	cin>>s;
	vector<string> ans=findRepeatedDnaSequences(s);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
}
