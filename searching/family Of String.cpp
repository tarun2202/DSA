/*	Family of Strings
	for a given value of n. find the kth character in the formed string S[n]. 
	String is formed in such as way as: S[i]=S[i-1].0.S[i-1]' 
	note: string follows 0 based indexing.
		Input: N=3 k=13
		Output: 0
		Explanation: S[3]=001011001101001  So kth character is: element present at 14 pos of S. 
	time complexity: O(log(2^(n+1))) ~ O(n+1) ~O(n)
*/

#include<bits/stdc++.h>
using namespace std;
int findKthCharacter(int n,int k){
	int low=0,high=pow(2,n+1)-2,mid;
	int bit=0;
	while(low<=high){
		mid=low+(high-low)/2;
		if(mid==k)
			return bit;
		//when moving right: toggle the bit	
		else if(k>mid){
			low=mid+1;
			bit=1-bit;
		}
		//when moving left: bit remains same
		else
			high=mid-1;	
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	int ans=findKthCharacter(n,k);
	cout<<ans;
}
