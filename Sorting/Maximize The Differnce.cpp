/*	Maximize The Differnce.
	Chef has gone shopping with his 5-year old son. They have bought N items so far. The items are numbered
	from 1 to N, and the item i weighs Wi grams.
	Chef's son insists on helping his father in carrying the items. He wants his dad to give him a few 
	items. Chef does not want to burden his son. But he won't stop bothering him unless he is given a few 
	items to carry. So Chef decides to give him some items. Obviously, Chef wants to give the kid less 
	weight to carry.
	However, his son is a smart kid. To avoid being given the bare minimum weight to carry, he suggests 
	that the items are split into two groups, and one group contains exactly K items. Then Chef will carry 
	the heavier group, and his son will carry the other group.
	Help the Chef in deciding which items should the son take. Your task will be simple. Tell the Chef the
	maximum possible difference between the weight carried by him and the weight carried by the kid.
	
		Input:  2
				5 2
				8 4 5 2 10
				8 3
				1 1 1 1 1 1 1 1
		Output: 17
				2		
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
	int t ;
	cin >> t ;
	while(t--){
   		int n , k;
   		cin>> n >> k ;
   		int i ;
   		k = min(k , n - k);
   		vector<int>w(n);
   		for(i = 0 ; i < n ; i++)
       		cin >> w[i];
   		sort(w.begin() , w.end());
   		long long sum = 0 ;
   		for(i = 0 ; i < k ; i++)
       		sum += w[i];
   		long long finalsum = 0 ;
   		for(i = k ; i < n ; i++)
       		finalsum += w[i];  
   		cout << finalsum - sum << endl;
	}
}
