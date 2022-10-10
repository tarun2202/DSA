/*	907. Sum of Subarray Minimums
	Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
	Since the answer may be large, return the answer modulo 109 + 7.
		Input: arr = [3,1,2,4]
		Output: 17
		Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
					 Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
					 Sum is 17.
	
	naive approach--> 	  TC: O(n^2)	SC: O(1)
	optimised approach--> TC: O(n)		SC: O(n)				 
*/

#include<bits/stdc++.h>
using namespace std;

//brute force--> generating all subarrays: find the min of all subarray and add to the ans variable.
/*int sumSubarrayMinimum(vector<int> &arr,int n){
	long long MOD=10e7;
	int ans=0, minm;
	for(int i=0;i<n;i++){
		minm=INT_MAX;
		for(int j=i;j<n;j++){
			minm=min(minm,arr[j]);
			ans= (ans%MOD + minm%MOD)%MOD;
		}
	}
	return ans;
}*/

//optimised approach
int sumSubarrayMinimum(vector<int>& arr, int n) {
    const unsigned int MOD = 1000000007;
	vector<int> nse(n), psoe(n);
    stack<int>st;
    //computing NSE[] --> O(n)
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            nse[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nse[st.top()]=n;
        st.pop();
    }
    //comouting PSAE[] --> O(n)
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            psoe[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        psoe[st.top()]=-1;
        st.pop();
    }
    int ans=0, cnt=0;
    //calculating the contribution of each element --> O(n)
    for(int i=0;i<n;i++){
        cnt=((long long)((i-psoe[i])%MOD*(nse[i]-i)%MOD)%MOD*arr[i]%MOD)%MOD;
        ans= (ans%MOD+cnt%MOD)%MOD;
    }
    return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int ans= sumSubarrayMinimum(arr,n);
	cout<<ans;	
}
