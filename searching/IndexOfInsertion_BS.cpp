/*	Index of Insertion
	Given a sorted array of distinct integers nums, and a target value, value, print the index if the target,
	is found. If not, print the index where it would be if it were inserted in order. You must write an 
	algorithm with O(logn) runtime complexity.
	Output Format: For each testcase, print the index if the target is found. If not, print the index 
	where it would be if it were inserted in order.
	
	Input: 5				Output: 0		
		   1 2 3 6 8				2
		   t=4						5
		   0						3
		   3
           12
           4
    time complexity: O(logn)
	space complexity: O(1)       
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n;
	cin >> n;
	vector<ll> v(n);
	for(int i = 0; i < n; i++) 
		cin >> v[i]; 
	int t;
	cin >> t;
	while(t--) {
		ll key;
		cin >> key;
		ll start = 0, end = n-1;
		//when target element is less than the 1st element of given array
		if(key < v[start]) { 
			cout << 0 << endl;
			continue;
		}            
		//when key element is gretaer than the last element of the given array 
		if(key > v[end]) { 
			cout << end+1 << endl; 
			continue;
		}  
		//when the key exist in-between the given array
		while(start <= end) {
			ll mid = start + (end-start)/2;
			if(key == v[mid]) {
				cout << mid << endl;
				break;
			}
			else if(key < v[mid]) 
				end = mid-1; 
			else  
				start = mid+1; 
		}
		//start: pointing to the element's pos just greater than the target
		//end: pointing to the elements's pos just smaller than the target
		if(start > end)
			cout << start << endl;
	}
    return 0;
}
