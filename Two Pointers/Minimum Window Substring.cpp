/*	76. Minimum Window Substring
	Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that 
	every character in t (including duplicates) is included in the window. If there is no such substring, return the 
	empty string "".
	The testcases will be generated such that the answer is unique.
	A substring is a contiguous sequence of characters within the string.
	
		Input: s = "ADOBECODEBANC", t = "ABC"
		Output: "BANC"
		Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
		
	naive approach--> TC:		SC: 
	optimised approach--> TC: 	SC: 	
*/

#include<bits/stdc++.h>
using namespace std;
//optimised approach
string minWindow(string s, string t){
	if(t.length()==0)
		return "";
	vector<int>freqS(256,0), freqT(256,0);
	int disChar=0;
	for(int i=0;i<t.length();i++){
		if(freqT[t[i]]==0)
			disChar++;
		freqT[t[i]]++;
	}	     
	int cnt=0, start=0, end;
	//finding my first valid window
	for(int i=0;i<s.length();i++){
		freqS[s[i]]++;
		if(freqS[s[i]]==freqT[s[i]])	
			cnt++;
		if(cnt==disChar){
			end=i;
			break;
		}	
	}
	if(cnt<disChar)
		return "";
	int anss=start, anse=end, minm=end-start+1;
	while(end<s.length()){
		//Trimming
		while(freqS[s[start]]>freqT[s[start]]){
			freqS[s[start]]--;
			start++;
		}
		//update
		if(end-start+1<minm){
			minm=end-start+1;
			anss=start;
			anse=end;
		}
		end++;
		if(end<s.length())
			freqS[s[end]]++;
	}	
	return s.substr(anss,minm);
}

int main(){
	string s;
	string t;
	cin>>s;
	cin>>t;
	cout<<minWindow(s,t);
}


