/*	1201. Ugly Number III
	An ugly number is a positive integer that is divisible by a, b, or c.
	Given four integers n, a, b, and c, return the nth ugly number.
			
			Input: n = 3, a = 2, b = 3, c = 5
			Output: 4
			Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
			
	Time Complexity: O(log(right-left))
	space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
long long calLCM(long long x, long long y){
	long long gcd=__gcd(x,y);
	return (x*y)/gcd;
}
long long countNumbers(long long mid,long long a,long long b, long long c){
	return mid/a + mid/b +mid/c - mid/calLCM(a,b)-mid/calLCM(b,c)-
		mid/calLCM(a,c)	+ mid/calLCM(a,(calLCM(b,c)));
}
int findUglyNumber(long long n,long long a,long long b,long long c){
	long long left=min(a,min(b,c)), right= n*min(a,min(b,c)),mid;
	long long ans=0;
	while(left<=right){
		mid=left+(right-left)/2;
		if(countNumbers(mid,a,b,c)<n)
			left=mid+1;
		else{
			if(countNumbers(mid-1,a,b,c)<n){
				ans=mid;
				break;
			}
			else
				right=mid-1;
		}	
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,a,b,c;
		cin>>n>>a>>b>>c;
		long long ans=findUglyNumber(n,a,b,c);
		cout<<ans<<endl;	
	}
}
