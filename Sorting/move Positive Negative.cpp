/*	move Positive Negative
	given an array nums of size n contains both negative and positive elements in it. Return an array which has all
	negative elements first followed by positive elements while keepuing the relative order of negative elements.
		
		input: nums= [-9, 1, -7, -2, 6, 3, 8, -4]
		output:      [-9, -7, -2, -4, 6, 3, 8, 1] 
	
	time complexity: O(n)
	space complexity: O(1)	

*/
#include<bits/stdc++.h>
using namespace std;

/*	naive approach-
	using 2 auxillary arrays: 1st keep all the negative elements in arr, 2nd keeps all the elements which are positive
	then first place negative elements in the original array followed by positive elements.
		time complexity: O(n)
		space complexity: O(n) 
*/

//optimised approach
void movePositiveNegative(vector<int>&nums,int n){
	int i=0,count=0;
	while(i<n){
		if(nums[i]<=0){
			if(i!=count)
				swap(nums[i],nums[count]);
			count++;	
		}
		i++;
	}
}
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	movePositiveNegative(nums,n);
	for(int i=0;i<n;i++)
		cout<<nums[i]<<" ";
}
