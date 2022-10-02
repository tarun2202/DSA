/*	Consecutive Array Elements
	Given an unsorted array arr[] of size N, the task is to check whether the array consists of consecutive numbers or not.
        Input: N = 5, arr[] = {5, 4, 2, 1, 3}
        Output: Yes
        Explanation: All are consecutive elements, according to this order 1,2,3,4 and 5.
				
	Naive Approach--> 		TC: O(n^2)   SC: O(1) 
	Optimised Approach--> 	TC: O(n)     SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
//Naive Approach
/*bool areConsecutives(long long arr[], int n) { 
	 sort(arr, arr+n);
     int diff=0;
     for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]==1)
            diff = 1;
        else 
            diff = 0;
     }     
     return (diff==1) ? true: false;
}*/

//optimised Approach
bool areConsecutives(long long arr[], int n) { 
    long long minm=LLONG_MAX;
    unordered_map<long long, long long>m;
    for(int i=0;i<n;i++){
        m[arr[i]]=0;    //populating hashmap with the elements as key, value here are insignificant(can be anything)
        minm=min(minm,arr[i]);  //finding min element of array
    }    
    for(int i=minm;i<=minm+n-1;i++)
        if(m.find(i)==m.end())  //when input array element is not found: means the array is consecutive in nature--> return false
            return false;
    return true;    //input array has consecutive elements--> return true     
}

int main(){
	int n;
	cin>>n;
	long long arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<areConsecutives(arr, n);			
}
