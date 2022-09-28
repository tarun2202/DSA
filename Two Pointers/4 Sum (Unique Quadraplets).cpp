/*	15. 3Sum (Unique Triplets)
	Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], 
	nums[d]] such that:
		-> 0 <= a, b, c, d < n
		-> a, b, c, and d are distinct.
		-> nums[a] + nums[b] + nums[c] + nums[d] == target
	You may return the answer in any order.
		
	Input: nums = [1,0,-1,0,-2,2], target = 0
	Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

	
	Naive force: 		TC- O(n^4)	SC:O(x.y)	where x: number of quadruplets, y: 4- size of each triplets
	optimised approach: TC- O(n^3+ (nlogn)) ~ O(n^3)	SC: O(x.y)

*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >ans;
vector<vector<int> > findTriplets(vector<int>& nums, int n,int target){
	sort(nums.begin(),nums.end()); //sorting inorder to apply 2 pointer technique
	for(int i=0;i<n;i++){
		if(i>0 && nums[i]==nums[i-1])
			continue;
		for(int j=i+1;j<n;j++){
			if(j>i+1 && nums[j]==nums[j-1])
				continue;
			else{
				int p1=j+1, p2=n-1, rem=target -1*(nums[i]+nums[j]);
				while(p1<p2){
					if(nums[p1]+nums[p2]<rem)
						p1++;
					else if(nums[p1]+nums[p2]>rem)
						p2--;
					else{
						vector<int>temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[p1]);
						temp.push_back(nums[p2]);
						ans.push_back(temp);
						if(nums[p1]==nums[p2])
							break;
						else{
							int v1=nums[p1], v2=nums[p2];
							while(nums[p1]==v1)	p1++;
							while(nums[p2]==v2)	p2--;
						}	
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
	int target;
	cin>>target;	
	ans=findTriplets(nums,n,target);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}	
}

//Naive Approach: 
/*set<vector<int> > ans;
void Print_Vector(vector<int> Vec)
{
    for (int i = 0; i < Vec.size(); i++) {
        cout << Vec[i] << " ";
    }
    cout << endl;
    return;
}
set<vector<int> > findQuadruplets(vector<int>&nums, int n,int target){
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            for(int k=j+1;k<n-1;k++){
            	for(int l=k+1;l<n;l++){
            		if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                    	vector<int>temp;
                    	temp.push_back(nums[i]);
                    	temp.push_back(nums[j]);
                    	temp.push_back(nums[k]);
                    	temp.push_back(nums[l]);
                    	sort(temp.begin(),temp.end());
                    	ans.insert(temp);
                	}	
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
    int target;
	cin>>target;    
    ans=findQuadruplets(nums,n,target);
    for (auto it = ans.begin(); it != ans.end(); it++)
        Print_Vector(*it);
}
*/
