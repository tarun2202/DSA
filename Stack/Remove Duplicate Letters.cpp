/*	316. Remove Duplicate Letters
	Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure 
	your result is the smallest in lexicographical order among all possible results.
		Input: s = "cbacdcbc"
		Output: "acdb"
    
    time complexity:  O(n)
    space complexity: O(1)    
*/

#include<bits/stdc++.h>
using namespace std;
string removeDuplicateLetters(string s){
	int freq[26]={0};
	int visited[26]={0};
	string ans="";
    // Stores count of each character
	for(int i=0;i<s.length();i++)
		freq[s[i]-'a']++;
	for(int i=0;i<s.length();i++){
		//decrement the count of current character
		freq[s[i]-'a']--;
		//check if already not in answer
		if(!visited[s[i]-'a']){
            // Last character > S[i] and its count > 0
			while(ans.size()>0 && ans.back()>s[i] && freq[ans.back()-'a']>0){
				// Mark letter unvisited
                visited[ans.back() - 'a'] = 0;
                ans.pop_back();
			}
			// Add s[i] in res and mark it visited
            ans += s[i];
            visited[s[i] - 'a'] = 1;
		}
	}
	return ans;
}
int main(){
	string s;
	cin>>s;
	string ans=removeDuplicateLetters(s);
	cout<<ans;
}
