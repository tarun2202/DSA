#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int i, int n){
	if(i>n/2)
		return;
	int maxm=i;
	if(arr[2*i]>arr[maxm])
		maxm=2*i;
	if(2*i+1<=n && arr[2*i+1]>arr[maxm])
		maxm=2*i+1;
	if(maxm!=i){
		swap(arr[i], arr[maxm]);
		heapify(arr, maxm, n);
	}			
}
void buildHeap(int arr[], int n){
	//int start=n/2;
	for(int i=n/2; i>=1; i--)
		heapify(arr, i, n);
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	buildHeap(arr, n);
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";	
}
