/*Insertion Sort: inserting the element at its deserving position in the already sorted array. 
	time complexity: O(n^2)
	space complexity:O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	//starts from idx 1 of arr: assuming that the first element of array is always sorted.	
	for(int i=1;i<n;i++){
		int j=i;
		while(j>0 && arr[j]<arr[j-1]){ //putting the jth element at its deserving location in array
			int temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j--;
		}
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";	
}
