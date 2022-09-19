/*	Manhattan distances
	Given n integer coordinates. The task is to find sum of Manhattan distance between all pairs of 
	coordinates. Answer might be large. Take modulo by 10^9+7. Manhattan Distance between two points 
		(x1, y1) and (x2, y2) is: |x1 – x2| + |y1 – y2|
		
	Input: 	4
		   	-1 5
			1 6
			3 5
			2 3	
	Output: 22
	Explanation: Distance of { 1, 6 }, { 3, 5 }, { 2, 3 } from { -1, 5 } are 3, 4, 5 respectively.
				 Therefore, sum = 3 + 4 + 5 = 12
				 Distance of { 3, 5 }, { 2, 3 } from { 1, 6 } are 3, 4 respectively. Therefore, sum = 12 + 3 + 4 = 19
				 Distance of { 2, 3 } from { 3, 5 } is 3. Therefore, sum = 19 + 3 = 22.	
	
	Naive approach: O(n^2)
	Optimised Approach: O(nlogn)
	Space complexity: O(1)			 	

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll m = 1e9 + 7 ;
int main() {
    int n ;
	cin >> n ;
	vector<int>axis1(n);
	vector<int>axis2(n);
	int i ;
	for(i = 0 ; i < n ; i++){
		cin >> axis1[i];
		cin >> axis2[i];
	}
	sort(axis1.begin() , axis1.end());
	sort(axis2.begin() , axis2.end());
	ll t_sum1 = 0 ;
	ll t_sum2 = 0 ;
	for(i = 0 ; i < n ; i++){
		t_sum1 += axis1[i];
		t_sum2 += axis2[i];
	}
	ll ans1 = 0;
	ll ans2 = 0 ;
	ll finalans;
	for(i = 0 ; i < n ; i++){
		t_sum1 -= axis1[i];
		t_sum2 -= axis2[i];
		ans1 += (t_sum1 % m);
		ans1 -= (axis1[i] * (n - 1 - i)) % m ;
		ans2 += (t_sum2 % m);
		ans2 -= (axis2[i] * (n - 1 - i))%m;
	}
	finalans = (ans1 + ans2) % m;
	cout << finalans << endl;
    return 0;
}
