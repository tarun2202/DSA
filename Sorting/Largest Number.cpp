/*	179. Largest Number
	Given a list of non-negative integers nums, arrange them such that they form the largest number and 
	return it.
	Since the result may be very large, so you need to return a string instead of an integer.
		
		Input: nums = [3,30,34,5,9]
		Output: "9534330"
	
	time complexity:O(nlogn)   where, n: length of nums int array
	space complexity: O(n)	
*/

#include<bits/stdc++.h>
using namespace std;
bool compare(string a, string b){
	return (a+b) > (b+a);
}
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	vector<string>s;
	//converting digits in nums to string
	for(int x:nums)
		s.push_back(to_string(x)); 
	sort(s.begin(),s.end(),compare);
	string ans;
	//puting vector of string in string
	for(string x:s)
		ans += x;	
	int start=0;
	//edge case: dealing with nums=[0,0,0], return ans="0"
	while(ans[start]=='0' && start<=ans.size()-1)	
		start++;
	cout<<ans.substr(start);			
}

