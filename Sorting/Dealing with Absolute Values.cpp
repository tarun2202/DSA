/*	Dealing with The Absolute Values
	given an array of size n. find:
		1) min value of |arr[i]-arr[j]|
		2) max vaue of |arr[i]-arr[j]|

	naive Approach: iterate of all the pair of the array and then find the update the min upon finding the 
	pair which has the min differernce between them.
		time complexity: O(n^2)
		
	Optimised Approach: first sort the array elements. 
	Now to find the max of diff of two elements will be: arr[n-1]-arr[0]
	and to find min of diff of two elements: iterate over the array and update the min value upon finding the
	min differnce.
		time complexity: O(nlogn) 	
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int minimum=INT_MAX, maximum=INT_MIN;
	sort(arr.begin(),arr.end());
	maximum=arr[n-1]-arr[0];
	for(int i=0;i<n-1;i++)
		minimum=min(abs(arr[i+1]-arr[i]),minimum);
	cout<<maximum<<" "<<minimum;	
}
