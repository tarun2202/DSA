/*	Pair Sum 
	Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements
	in Arr whose sum is exactly X.
	Input: N = 6, X = 16	Arr[] = {1, 4, 45, 6, 10, 8}
	Output: Yes
	Explanation: Arr[3] + Arr[4] = 6 + 10 = 16
	
	naive apporach--> 		TC: O(n^2)		SC: O(1)	generating all pair and check sum of each pair
	better appraoch-->		TC: O(nlogn)	SC: O(1)	sorted the input array, then apply two pointers approach
	optimised approach--> 	TC: O(n) 		SC: O(n)	using the concept of hash table
*/

#include<bits/stdc++.h>
using namespace std;

// using 2 for loop: 1st to create frequency of each elements, 2nd loop for checking element presence. 	TC: O(2n)
/*bool findPair(int arr[], int n, int x){
	unordered_map<int,int> m;	//working fine other ide
	for(int i=0;i<n;i++)
		m[arr[i]]++;
	for(int i=0;i<n;i++){
		if(m.find(x-arr[i])!=m.end()){	//returns true--> when x-arr[i]: 2nd element is present in hash table
			int f=m[x-arr[i]];	//getting the frequency of 2nd element
			//when 1st and 2nd element is same: check for frequency--> if >1, means there exist more than one occurence of 1st element
			if(arr[i]==x-arr[i] && f>1)	
				return true;
			//when 2nd and 1st element are different	
			else if(arr[i]!=x-arr[i])
				return true;
		}		
	}
	//when there exist no pair whose sum is equal to x
	return false;	
}
*/

// using a single for loop: to find the pair in the array --> TC:O(n)
bool findPair(int arr[], int n, int x){
	unordered_map<int,int> m;	//working fine other ide
	for(int i=0;i<n;i++){
		// first checking the 2nd element presence: if present- return true
		// here element itself won't be a contender for the 2nd element of the pair- so no need to check for frequency of 1st element
		if(m.find(x-arr[i])!=m.end())	
			return true;
		m[arr[i]]=0;	
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int x;
	cin>>x;
	cout<<findPair(arr,n,x);	
}
