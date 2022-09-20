/*	870. Advantage Shuffle
	You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with 
	respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
	Return any permutation of nums1 that maximizes its advantage with respect to nums2.
		
		Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
		Output: [2,11,7,15]
		
	time complexity:
	space complexity:	

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>nums1(n);
	for(int i=0;i<n;i++)
		cin>>nums1[i];
	vector<int>nums2(n);	
	for(int i=0;i<n;i++)
		cin>>nums2[i];
	int i;
	vector<pair<int,int> >nums3;
	for(int i=0;i<n;i++)
		nums3.push_back({nums2[i],i});
	sort(nums1.begin(),nums1.end());
	sort(nums3.begin(),nums3.end());
	vector<int>ans(n,-1);
	vector<int>unused;
	int pos=0;
	for(i=0;i<n;i++){
		if(nums1[i]>nums3[pos].first){
			ans[nums3[pos].second]=nums1[i];
			pos++;
		}
		else
			unused.push_back(nums1[i]);
	}			
	for(i=0;i<n;i++){
		if(ans[i]==-1){
			ans[i]=unused.back();
			unused.pop_back();
		}
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
}
