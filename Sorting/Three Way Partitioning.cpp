/*	GFG: Three way partitioning
	Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
		1) All elements smaller than a come first.
		2) All elements in range a to b come next.
		3) All elements greater than b appear in the end.
	The individual elements of three sets can appear in any order. You are required to return the modified array.

		Time complexity: O(n)
		space complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
void threeWayPartition(vector < int > & array, int a, int b) {
    int i = 0;
    int j = array.size() - 1;
    // seperate elements which are smaller to 'a' and greater or equal to 'a'
    while (i <= j) {
        if(array[i]<a)
            i++;
        else if(array[j]>=a)
            j--;
        else swap(array[i],array[j]);    
    }
    //seperate elements which are smaller or equal to 'b' and greater to 'b'.
    int k=i;
    j=array.size()-1;
    while(k<=j){
        if(array[k]<=b)
            k++;
        else if(array[j]>b)
            j--;
        else
            swap(array[k],array[j]);
    }
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int a,b;
	cin>>a>>b;	
	threeWayPartition(nums,a,b);
	for(int i=0;i<n;i++)
		cout<<nums[i]<<" ";	
}
