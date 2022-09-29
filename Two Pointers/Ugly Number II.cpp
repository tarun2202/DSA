/*	Ugly Number II
	An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
	Given an integer n, return the nth ugly number.
		Input: n = 10
		Output: 12
		Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

	time complexity:  O(n)
	space complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;
int findNthUglyNum(int n){
	int arr[n];
	arr[0]=1;
	int p1=0, p2=0, p3=0;
	for(int i=1;i<n;i++){
		int val=min(arr[p1]*2,min(arr[p2]*3,arr[p3]*5));
		arr[i]=val;
		if(val==arr[p1]*2)	p1++;
		if(val==arr[p2]*3)	p2++;
		if(val==arr[p3]*5)	p3++;
	}
	return arr[n-1];
}
int main(){
	int n;
	cin>>n;
	cout<<findNthUglyNum(n);
}

