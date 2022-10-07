/*	242. Valid Anagram
	Given two strings s and t, return true if t is an anagram of s, and false otherwise.
		Input: s = "anagram", t = "nagaram"
		Output: true
	
	time complexity: O(nlogn) where n: max length of input string
	space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t)
        return true;
    else 
        return false;
}
int main() {
    string s,t;
    cin>>s>>t;
    cout<<isAnagram(s,t);        
}
