/*	Segregate Even and Odd numbers
	Given an array Arr[], write a program that segregates even and odd numbers. The program should put all even 
	numbers first in sorted order, and then odd numbers in sorted order.
		Arr[] = {12, 34, 45, 9, 8, 90, 3}
		Output: 8 12 34 90 3 9 45
		
	Time Complexity: O(N log(N))
	Auxiliary Space: O(N)	
*/

#include<bits/stdc++.h>
using namespace std;
void segregateEvenOdd(int arr[], int n) {
    int i=0,j=0;
    while(i<n){
        if(arr[i]%2==0)
            swap(arr[i],arr[j++]);
        i++;
    }
    sort(arr,arr+j);
    sort(arr+j,arr+n);
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
