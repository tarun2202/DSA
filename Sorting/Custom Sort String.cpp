/*	791. Custom Sort String
	You are given two strings order and s. All the characters of order are unique and were sorted in some 
	custom order previously.
	Permute the characters of s so that they match the order that order was sorted. More specifically, if a 
	character x occurs before a character y in order, then x should occur before y in the permuted string.
	
		Input: order = "cba", s = "abcd"
		Output: "cbad"
	
	time complexity: O(klogk)
	space complexity:O(k)	
		where k: length of string s
*/

#include<bits/stdc++.h>
using namespace std;
//checking the rank of the two character of s string: if rank of p1 is less than that of p2, return true
bool compare(pair<char,int> p1, pair<char,int> p2){
	return p1.second < p2.second;
}
int main(){
	string a,b;
	cin>>a>>b;
	//initializing the rank with -1, such that when i iterate over a I only touched the elements present.
	//and that it won't have any garbage value.
	int rank[26]={-1};
	//initialising the rank within a: as the index.
	for(int i=0;i<a.length();i++)
		rank[a[i]-'a']=i;
	vector<pair<char,int> >v;
	//having the vector of pair: which contains char of b and its rank in the string b
	for(int i=0;i<b.length();i++)
		v.push_back({b[i],rank[b[i]-'a']});
	sort(v.begin(),v.end(),compare);
	string ans;
	for(int i=0;i<v.size();i++)
		ans+=v[i].first;
	cout<<ans;			
}
