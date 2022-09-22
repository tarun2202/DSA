/*	Inversion Count
	Given an array of integers. Find the Inversion Count in the array. 
	Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
	If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the 
	inversion count is the maximum. 
	Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
	
	Input: N = 5, arr[] = {2, 4, 1, 3, 5}
	Output: 3
	
	Input: N = 5, arr[] = {2, 3, 4, 5, 6}
	Output: 0	
	
	time complexity:O(n.logn)
	space complexity: {O(n) + [O(logn)-->recursive call stack]} ~ O(n)		   
*/

#include<bits/stdc++.h>
using namespace std;
void mergeProcess(int arr[],int s1, int e1, int s2, int e2, int n,int &count){
	int temp[n];
	int i=s1, j=s2, k=s1;
	while(i<=e1 && j<=e2){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else{
			count+=(e1-i+1);
			temp[k++]=arr[j++];	
		}	
	}
	while(i<=e1)
		temp[k++]=arr[i++];
	while(j<=e2)
		temp[k++]=arr[j++];
	for(int i=s1;i<=e2;i++)
		arr[i]=temp[i];		
}
void mergeSort(int arr[],int i, int j,int n,int &count){
	if(i==j)
		return;
	int m=(i+j)/2;	
	mergeSort(arr,i,m,n,count);
	mergeSort(arr,m+1,n-1,n,count);
	mergeProcess(arr,i,m,m+1,j,n,count);	
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int count=0;	
	mergeSort(arr,0,n-1,n,count);	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl<<count;	
}
