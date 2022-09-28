/*	15. 3Sum (Unique Triplets)
	Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, 
	and j != k, and nums[i] + nums[j] + nums[k] == 0.
	Notice that the solution set must not contain duplicate triplets.
		Input: nums = [-1,0,1,2,-1,-4]
		Output: [[-1,-1,2],[-1,0,1]]
	
	Naive force: 		TC- O(n^3)	SC:O(x.y)	where x: number of triplets, y: 3- size of each triplets
	optimised approach: TC- O(n^2+ (nlogn)) ~ O(n^2)	SC: O(x.y)

*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >ans;
vector<vector<int> > findTriplets(vector<int>& nums, int n){
	sort(nums.begin(),nums.end()); //sorting inorder to apply 2 pointer technique
	for(int i=0;i<n;i++){
		if(i>0 && nums[i]==nums[i-1])
			continue;
		else{
			int rem=-1*nums[i], p1=i+1, p2=n-1;
			while(p1<p2){
				if(nums[p1]+nums[p2]<rem)
					p1++;
				else if(nums[p1]+nums[p2]>rem)
					p2--;
				else{
					vector<int>temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[p1]);
					temp.push_back(nums[p2]);
					ans.push_back(temp);
					if(nums[p1]==nums[p2])	//when the elements between p1 and p2 are same.
						break;
					else{	
					// when p1 points to repeating elements, skip all those repeating elements to ensure uniquness.
					// same logic applies to elemts pointed by p2. 
						int v1=nums[p1], v2=nums[p2];
						while(nums[p1]==v1) p1++;
						while(nums[p2]==v2)	p2--;
					}	
				}		
			}
		}	
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	ans=findTriplets(nums,n);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}	
}

//Naive Approach: 
/*set<vector<int>> ans;
void Print_Vector(vector<int> Vec)
{
    for (int i = 0; i < Vec.size(); i++) {
        cout << Vec[i] << " ";
    }
    cout << endl;
    return;
}
set<vector<int>> findTriplets(vector<int>&nums, int n){
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    ans=findTriplets(nums,n);
    for (auto it = ans.begin(); it != ans.end(); it++)
        Print_Vector(*it);
}*/

