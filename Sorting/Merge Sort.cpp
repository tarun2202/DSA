/*	Merge Sort Implementation:
	input: n=8
		   arr: [8 7 6 5 4 3 2 1]
	output:arr: [1 2 3 4 5 6 7 8]
		
	time complexity:O(n.logn)
	space complexity: {O(n) + [O(logn)-->recursive call stack]} ~ O(n)		   
*/

#include<bits/stdc++.h>
using namespace std;
void mergeProcess(int arr[],int s1, int e1, int s2, int e2, int n){
	int temp[n];
	int i=s1, j=s2, k=s1;
	while(i<=e1 && j<=e2){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];	
	}
	while(i<=e1)
		temp[k++]=arr[i++];
	while(j<=e2)
		temp[k++]=arr[j++];
	for(int i=s1;i<=e2;i++)
		arr[i]=temp[i];		
}
void mergeSort(int arr[],int i, int j,int n){
	if(i==j)
		return;
	int m=(i+j)/2;	
	mergeSort(arr,i,m,n);
	mergeSort(arr,m+1,n-1,n);
	mergeProcess(arr,i,m,m+1,j,n);	
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	mergeSort(arr,0,n-1,n);	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
