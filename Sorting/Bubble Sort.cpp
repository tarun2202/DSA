// Bubble Sort

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	/*	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j+1]<=arr[j]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}*/
	
	//optimised Implementation: 
	bool sorted=false;
	while(!sorted){
		int i=0;
		sorted=true;
		while(i<n-1){	//til n-1: to ensure that i don't get idx out of bound exception--> comparing 
		//arr[n-2]>arr[n-1]
			if(arr[i]>arr[i+1]){
				swap(arr[i],arr[i+1]);
				sorted=false;	//if swapping happens then there is more swapping to be happended to make array sorted
			}
			i++;	
		}
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";	
}
