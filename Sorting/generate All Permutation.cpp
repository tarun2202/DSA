/*	Generate All Possible Permutation
	for a given array consists of n elements, generate all the possible permutations of array in 
	lexicographical order.
		input: arr=[1 2 3]
		output: [1 2 3], [1 3 2], [2 1 3], [2 3 1], [3 1 2], [3 2 1]
		
	time complexity:O(nlogn) -->because of sorting
	space complexity: O(1)
		
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	//sorting the array-->inorder to start from the smallest lexicographical order
	sort(nums.begin(),nums.end());	
	int total=1;
	//finding the total possible number of permutations
	for(int i=1;i<=n;i++){
		total *= i;
	}
	//printing the smallest permutation of given array
	for(int i=0;i<n;i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	int rem_permuation=total-1;	
	while(rem_permuation--){
		int k, l;
    	for (k = n - 2; k >= 0; k--) {
        	if (nums[k] < nums[k + 1])
            	break;
   		}
    	if (k < 0)   //my array is already at its highest lexicographical order : whole array in                             descending order
        	reverse(nums.begin(), nums.end());
    	else {
        	for (l = n - 1; l > k; l--) {
            	if (nums[l] > nums[k]) 
                	break;
        	} 
        	swap(nums[k], nums[l]);
        	//reverse(nums.begin() + k + 1, nums.end());
			int start=k+1, end=n-1;
        	while(start<=end){
            	swap(nums[start],nums[end]);
            	start++;
            	end--;
        	}
    	}
    	for(int i=0;i<n;i++)
    		cout<<nums[i]<<" ";
		cout<<endl;		
	}	
}
