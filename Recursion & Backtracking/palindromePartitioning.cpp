/*	131. Palindrome Partitioning
	Given a string s, partition s such that every substring of the partition is a palindrome. 
	Return all possible palindrome partitioning of s.
	
	Input: s = "aab"
	Output: [["a","a","b"],["aa","b"]]
	
	time complexity: O[(2^n)*(n/2)*k]  o(2^n)- for generating all substring, 
	O(n/2)- checking palindrome or not, O(k)- to store the palindromic substring in another data structure.
	space complexity: O[k*x]  k is the avg length of palindrome substring for x substring in final ans
	auxillary space : O(n) n is the height of the recursion tree
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<string> >ans;
bool isPalindrome(string s,int start,int end){
	while(start<=end){
		if(s[start++]!=s[end--])
			return false;
	}
	return true;
}
void palindromePart(string s,vector<string>& sub,int index){
	//base case
	if(index==s.length()){
		ans.push_back(sub);
		return;
	}
	for(int i=index;i<s.length();i++){
		if(isPalindrome(s,index,i)){
			sub.push_back(s.substr(index,i-index+1));
			palindromePart(s,sub,i+1);
			sub.pop_back();
		}
	}
}

int main(){
	string s;
	cin>>s;
	vector<string>sub;
	palindromePart(s,sub,0);
	cout<<"[";
	for(int i=0;i<ans.size();i++){
		cout<<"[";
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<"]";	
	}
	cout<<"]";
}
