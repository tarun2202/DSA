/*	46. Permutations

	Given an array nums of distinct integers, return all the possible permutations. 
	You can return the answer in any order.
	Input: nums = [1,2,3]
	Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
void permute(vector<int> & nums,int i){
        int n=nums.size();
        if(i==n-1){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            permute(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	permute(arr,0);
	for(int i=0;i<ans.size();i++){
		cout<<endl;
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j];
		}
	}    	
} 
 
 
