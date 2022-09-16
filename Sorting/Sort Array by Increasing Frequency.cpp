/*	Sort by Frequency
	Given an integer array nums, sort the array according to frequency of elements. That is elements that 
	have higher frequency come first. If frequencies of two elements are same, then smaller number comes 
	first.
		Input:  2
			    5
           		5 5 4 6 4
                5
           		9 9 9 2 5
    	Output: 4 4 5 5 6
				9 9 9 2 5 
	time complexity: O(nlogn)
	space complexity:O(n)		
			      
*/

#include<bits/stdc++.h>
using namespace std;
class triplet{
	public:
	int val;
	int fre;
	int idx;
};
bool compare(triplet t1,triplet t2){
	if(t1.fre!=t2.fre)
		return t1.fre < t2.fre;
	if(t1.val!=t2.val)
		return t1.val < t2.val;
	return t1.idx < t2.idx;		
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>nums(n);
		for(int i=0;i<n;i++)
			cin>>nums[i];
		vector<int>freq(61,0);
		for(int i=0;i<=n;i++)
			freq[nums[i]]++;
		vector<triplet> v;
		for(int i=0;i<n;i++){
			triplet t;
			t.val=nums[i];
			t.fre=freq[nums[i]];
			t.idx=i;
			v.push_back(t);
		}		
		sort(v.begin(),v.end(),compare);
		for(int i=0;i<n;i++)
			cout<<v[i].val<<" ";
		cout<<endl;		
	}
}
