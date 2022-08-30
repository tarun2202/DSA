//time complexity: O(log2(k))
//space complexity: O(log2(k))

#include<bits/stdc++.h>
using namespace std;
double calExpo(double n,int k){
	if(k==0)
		return 1.0; //sice N^0 is always 1
	if(k<0){
		n=1/n;
		k=abs(k);
	}
	double x=calExpo(n,k/2);
	//for k=5: N^5 = N^2 * N^2 * (N)(missing part from x: for all k is odd)
	//for k=6: N^6 = N^2 * N^2 * N^2
	if(k%2==0)
		return x*x;
	return x*x*n;		
}
int main(){
	double n;
	int k;
	cin>>n>>k;
	double ans = calExpo(n,k);
	cout<<ans;
}
