/*	47. Permutations II

	Given a collection of numbers, nums, that might contain duplicates, 
	return all possible unique permutations in any order.
	Input: nums = [1,1,2]
	Output:[[1,1,2], [1,2,1], [2,1,1]]
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
        int freq[21]={0};
        
        for(int j=i;j<n;j++){
        	if(freq[nums[j]+10]==0){
            	swap(nums[i],nums[j]);
            	permute(nums,i+1);
            	swap(nums[i],nums[j]);
        	}
        	freq[nums[j]+10]++;
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
 
 
