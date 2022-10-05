/*  525. Contiguous Array
    Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
        Input: nums = [0,1]
        Output: 2
        Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

    Naive Approach-->       TC: O(n^2)   SC: O(1) 
    Optimised approach-->   TC: O(n)     SC: O(n)    
*/

#include<bits/stdc++.h>
using namespace std;
//Naive Approach- 
/*int continousArray(int arr[],int n){    
    int sum=0, ans=INT_MIN, len=0;
    for(int i=0;i<n;i++){
        sum = (arr[i]==0)? -1 : 1;
        for(int j=i+1;j<n;j++){
            (arr[j]==0) ? (sum+=-1) : (sum+=1);
            if(sum==0){
                len=j-i+1;
                ans=max(len,ans);
            }
        }
    }
    return ans;
}*/

//OPTIMISED APPROACH: using hashmap
int continousArray(int arr[],int n){ 
    unordered_map<int,int>m;
    m.insert({0,-1});	//sum 0 at index -1 in hashmap
    int sum=0, ans=0; 
    //iterating over the array to find the max length of contiguous array
    for(int i=0;i<n;i++){
        sum += (arr[i]==0) ? -1: 1;	//taking 0 as -1 and 1 as 1 for calculating cummulative sum
        if(m.find(sum)!=m.end())	//checking if sum appeared before in hashmap or not
            ans=max(ans,i-m[sum]); 	//whenever we get subarray having repeated sum, we update the max len of ans
        else
            m.insert({sum,i});    	//if not seen before: put it in hashmap.
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans=continousArray(arr,n);
    cout<<ans;    
}

