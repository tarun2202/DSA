/*	Longest Substring Without Repeating Characters
	Given a string s, find the length of the longest substring without repeating characters.
	
		Input: s = "abcabcbb"
		Output: 3
		Explanation: The answer is "abc", with the length of 3.
	
	Naive Approach--> TC: O(n^2)	SC: O(1)	
	Optimised apporach--> TC: O(n)	SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
//Optimised Approach
int findLongestSubstring(string s){
	int n=s.length();
	//edge case: when the given string is empty
	if(n==0)
		return 0;
	int freq[256]={0};	//freq array for all 256 characters present, to ensure the distinct nature of substring
	int i=0,j=0;
	int ans=1;
	freq[s[0]]++;	//considering the substring with one character in it.
	while(j<n-1){
		if(freq[s[j+1]]==0){	//checking if next element is already present in the current substring or not.
			freq[s[j+1]]++;		//incrementing freq of current character by 1
			j++;				//increasing the length of current substring till we hit a repeating character
		}
		else{
			//as soon as we hit the repeating character in current string, we reduce 1st charcter of substring by 1 and 
			//starts hunting of next possible substring by incrementing i=i+1
			freq[s[i]]--;
			i++;
		}
		ans=max(j-i+1,ans);	//tracking the length is every valid substring with the distinct characters in them.	
	}
	return ans;
}

//naive approach
/*int findLongestSubstring(string str){
	int n=str.length();
	int len=0;
	for(int i=0;i<n;i++){
		int freq[256]={0};
		for(int j=i;j<n;j++){
			if(freq[str[j]]>0)
				break;
			else{
				freq[str[j]]++;
				len= max(len,j-i+1);
			}	
		}
	}
	return len;
}*/

int main(){
	string str;
	cin>>str;
	int ans=findLongestSubstring(str);
	cout<<ans;
}
