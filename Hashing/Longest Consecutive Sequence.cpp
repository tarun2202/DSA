/*  128. Longest Consecutive Sequence
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
        Input: nums = [100,4,200,1,3,2]
        Output: 4
        Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

    Naive approach-->     TC: O(nlogn)      SC: O(1)
    Optimised Approach--> TC: O(n)          SC: O(n)           
*/

#include<bits/stdc++.h>
using namespace std;

//Naive Approach 1
/*int findConsecutiveLength(int arr[],int n){
    int ans=0,count=0;
    // sort the array so that elements appear in ASC order
    sort(arr,arr+n);
    vector<int>temp;
    temp.push_back(arr[0]);
    // temp: have elements which contains no repeated elements
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1])
            temp.push_back(arr[i]);
    }
    // find the maximum length by traversing the array
    for(int i=0;i<temp.size();i++){
        //checking if current element is same than previous or not.
        if(i>0 && temp[i]==temp[i-1]+1)
            count++;
        else //reset counter to 1: as only 1 element is consecutive in nature.
            count=1;    
        ans = max(ans,count);   //update the maximum 
    }
    return ans;
}*/

//Naive Approach 2: BEST
/*int findConsecutiveLength(int arr[],int n){
	if(n==0)
		return 0;
	int ans=1, currLen=1;
	sort(arr,arr+n);
	for(int i=1;i<n;i++){
		if(arr[i]==arr[i-1]) //element got repeated	
			continue;
		else if(arr[i]==arr[i-1]+1){
			currLen++;
			ans=max(currLen, ans);
		}	
		else
			currLen=1;
	}
	return ans;
}*/
// Optimised Approach 1: O(n+ maxm-minm) ~ O(maxm-minm)
/*int findConsecutiveLength(int arr[],int n){
    unordered_map<int,int>m;
    int count=0, ans=0;
    int minm=INT_MAX, maxm=INT_MIN;
    for(int i=0;i<n;i++){
        minm=min(minm, arr[i]);
        maxm=max(maxm, arr[i]);
        m[arr[i]]++;
    }
    for(int i=minm;i<=maxm;i++){
        if(m.find(i)!=m.end()){
            count++;
            ans=max(ans,count);
        }
        else
            count=0;
    }
    return ans;
}*/

//optmised Approach- BEST : TC: O(n)	SC: O(n)
int findConsecutiveLength(int arr[],int n){    
    if(n==0)
        return 0;
    int len=1, ans=1;    
    unordered_set<int>s;
    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    for(int i=1;i<n;i++){
        if(s.find(arr[i]-1)==s.end()){
            int j=arr[i];
            while(s.find(j)!=s.end())
                j++;
            ans=max(ans,j-arr[i]);    
        }
    }       
    return ans; 
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans=findConsecutiveLength(arr,n);
    cout<<ans;    
}

