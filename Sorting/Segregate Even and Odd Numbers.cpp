/*	Segregate Even and Odd numbers
	Given an array Arr[], write a program that segregates even and odd numbers. The program should put all even 
	numbers first in sorted order, and then odd numbers in sorted order.
		Arr[] = {12, 34, 45, 9, 8, 90, 3}
		Output: 8 12 34 90 3 9 45
	
	optimised approach- 	
	Time Complexity: O(N log(N))
	Auxiliary Space: O(1)	
*/

#include<bits/stdc++.h>
using namespace std;

//naive approach: using 2 auxillary arrays:
	//time complexity: O(nlogn)
	//space complexity: O(n)

/*void segregateEvenOdd(int arr[], int n) {
	vector<int>even, odd;
	for(int i=0;i<n;i++){
        if(arr[i]%2==0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }
	sort(odd.begin(),odd.end());
	sort(even.begin(),even.end());
	int i,j=0,k=0;
	for(i=0;i<even.size();i++)
		arr[i]=even[i];	
	for(int j=i;j<n;j++)
		arr[j]=odd[k++];	
}*/

//optimised approach- using two pointers:
void segregateEvenOdd(int arr[], int n) {
	int i=0,j=n-1;
	while(i<=j){
		if(arr[i]%2==0)
			i++;
		else if(arr[j]%2!=0)
			j--;
		else
			swap(arr[i],arr[j]);		
	}
	sort(arr,arr+i);
	sort(arr+i,arr+n);
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	segregateEvenOdd(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";	
}
