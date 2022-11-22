#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int i, int n){
	if(i>n/2)
		return;
	int minm=i;
	if(arr[2*i] < arr[minm])
		minm=2*i;
	if(2*i+1 <= n and arr[2*i+1] < arr[minm])
		minm=2*i+1;
	if(i != minm){
		swap(arr[i], arr[minm]);
		heapify(arr, minm, n);
	}			
}
void buildMinHeap(int arr[], int n){
	for(int i=n/2;i>=1;i--)
		heapify(arr,i,n);	
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	buildMinHeap(arr,n);
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";	
}
