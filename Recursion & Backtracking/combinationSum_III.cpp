/*
	Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
		Only numbers 1 through 9 are used.
		Each number is used at most once.
	Return a list of all possible valid combinations. The list must not contain the same combination twice,
	and the combinations may be returned in any order.
	
	time complexity: 
	space complexity: 
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
void findCombination(int i,int t,vector<int> &ds,int k){
        if(t==0 && k==0){
            ans.push_back(ds);
            return;
        }
        if(t<0 || k<0)  return;
        if(i==10)   return;
        findCombination(i+1,t,ds,k);
        ds.push_back(i);
        findCombination(i+1,t-i,ds,k-1);
        ds.pop_back();
    }
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int>temp;
        findCombination(1,n,temp,k);
        return ans;
    }
int main(){
	int k,n;
	cin>>k>>n;
	ans = combinationSum3(k,n);
	for(int i=0;i<ans.size();i++){
        cout<<" [ ";
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
        cout<<"]";    
	}  
}  

