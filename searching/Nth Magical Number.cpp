/*	Nth Magical Number
	A positive integer is magical if it is divisible by either a or b. Given the three integers n, a, and b,
	return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.
		
		Input: n = 1, a = 2, b = 3
		Output: 2
		
	Naive Approach: iterating over the range where my answer lies [min(a,b) to n*min(a,b)], and keep checking
	for each number and check if it satisfy given constraints. if yes- increase counter and keep doing till
	count reaches N. and upon reaching return the current value of num as ans.
		time complexity: O(n)
	
	Efficient Approach:	Using the concept of binary search, 	
		time complexity: O(log(right-left))
*/

#include<bits/stdc++.h>
using namespace std;
//Naive Approach
/*int findMagicalNumber(int n,int a,int b){
	int ans=0,count=1,num=2;
	while(count<=n){
		if(num%a==0 || num%b==0){
			if(count==n){
				ans=num;
				break;
			}
			count++;
		}
		num++;
	}
	ans=num;
	return ans;
}
*/
//Efficient Approach
long long calLCM(long long a, long long b){
	long long gcd=__gcd(a,b);
	return (a*b)/gcd;
}
long long countNumbers(long long mid,long long a,long long b){
	return mid/a + mid/b - mid/calLCM(a,b);
}
int findMagicalNumber(long long n, long long a, long long b){
	long long left=min(a,b), right= n*min(a,b),mid;
	long long ans=0;
	long long const MOD=1e9+7;
	while(left<=right){
		mid=left+(right-left)/2;
		if(countNumbers(mid,a,b)<n)
			left=mid+1;
		else{
			if(countNumbers(mid-1,a,b)<n){
				ans=mid%MOD;
				break;
			}
			else
				right=mid-1;
		}	
	}
	return ans;
}
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	int ans=findMagicalNumber(n,a,b);
	cout<<ans;
}
