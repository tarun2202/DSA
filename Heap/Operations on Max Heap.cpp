#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int i, int n){
	if(i>n/2)
		return;
	int maxm=i;
	if(arr[2*i]>arr[maxm])
		maxm= 2*i;
	if(2*i+1<=n && arr[2*i+1]>arr[maxm])
		maxm=2*i+1;
	if(i!=maxm){
		swap(arr[i], arr[maxm]);
		heapify(arr, maxm, n);
	}			
}
void buildMaxHeap(int arr[],int n){
	for(int i=n/2;i>=1;i--)
		heapify(arr, i, n);
}
int getMax(int arr[]){
	return arr[1];
}
void insertElement(int arr[], int x, int &n){
	arr[n+1]=x;
	n++;
	int i=n;
	while(i>1 && arr[i]>arr[i/2]){
		swap(arr[i], arr[i/2]);
		i/=2;
	}
}
void deleteRoot(int arr[], int n){
	swap(arr[1], arr[n]);
	n--;
	heapify(arr, 1, n);
}
void deleteAtIndex(int arr[], int n, int delIdx){
	arr[delIdx]=INT_MAX;
	int i=delIdx;
	while(i>1 && arr[i]>arr[i/2]){
		swap(arr[i], arr[i/2]);
		i/=2;
	}
	deleteRoot(arr, n);
}
void printHeap(int arr[], int n){
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;	
}
int main(){
	int arr[1000];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	
	//creating max heap	
	buildMaxHeap(arr,n);
	
	//printing the heap elements
	cout<<"printing heap elements..."<<endl;
	printHeap(arr, n);	
	
	//get the maximum element in heap
	cout<<"largest element..."<<getMax(arr)<<endl;

	//insert at particular index
	int idx;
	cin>>idx;
	insertElement(arr, idx, n);
	printHeap(arr, n);
	//deleteing at particular index
	int delIdx;
	cin>>delIdx;
	deleteAtIndex(arr, n, delIdx);
	printHeap(arr, n);
}
