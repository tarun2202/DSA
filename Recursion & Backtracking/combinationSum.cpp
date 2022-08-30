/*
	given arr[n] n belongs to +ve integer and given integer target_sum: find the distinct combination
	with the sum is equal to target_sum.
	
	input: arr=[2 3 6 7]    target_sum=7 
	output: [2 2 3], [7]
	
	note: here element arr[i] can be taken multiple times.
	
	time complexity: O(target^n)
	space complexity: O(n+target)
*/

#include<bits/stdc++.h>
using namespace std;
void printCombinationSum(vector<int>&temp,vector<int>&candidates,int target,int i){
        if(target == 0){
            for(int i=0;i<temp.size();i++)
            	cout<<temp[i]<<" ";
            cout<<endl;	
            return;	
        }
        if(target < 0)  return;
        if(i == candidates.size())  return;
            
        temp.push_back(candidates[i]); 
        printCombinationSum(temp , candidates , target - candidates[i] , i);
        temp.pop_back();
        printCombinationSum(temp , candidates, target , i + 1);
    }
    void combinationSum(vector<int>& candidates,int target) {
        vector<int>temp;
        int i = 0;
        printCombinationSum(temp,candidates,target,i);
        //return ans ;
    }
    
int main(){
	int n;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int target;
	cin>>target;
	vector<int>temp;
	combinationSum(arr,target);	
}    
