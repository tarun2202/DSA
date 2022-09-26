/*	167. Two Sum II - Input Array Is Sorted
	Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers 
	such that they add up to a specific target number.
		Input: numbers = [2,7,11,15], target = 9
		Output: [1,2]
	
	time complexity: O(n) -->using 2 pointer appraoch	
*/

#include<bits/stdc++.h>
using namespace std;

 vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>index;
        int n=numbers.size();
        int i=0,j=n-1;
		int count=0;
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                index.push_back(i);
                index.push_back(j);
                //break;
				count++;
            }
            else if(numbers[i]+numbers[j]>target)
                j--;
            else
                i++;
        }
		cout<<count<<endl;
        return index;
    }
int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int target;
	cin>>target;
	vector<int>index=twoSum(nums,target);
	for(int i=0;i<index.size();i++)
		cout<<index[i]<<" ";
}
