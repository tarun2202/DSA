/*	Sort the given array after applying the given equation
	Given a sorted integer array Arr[ ] of size N, and three integers A, B, and C. The task is to find a 
	new array  where ith element of the new array = A * Arr[i] * Arr[i] + B * Arr[i] + C where A ? 0. You 
	have to print the new array in sorted (ascending) order.
		Input:A = -1, B = 2, C = -1.
			  N = 6
			  Arr[] = {-1, 0, 1, 2, 3, 4}
		Output: [-9 -4 -4 -1 -1 0]
	
	naive approach: T.C: O(nlogn)
					S.C: O(1)
	optimised Approach: T.C: O(n)
						S.C: O(n)						
*/

#include<bits/stdc++.h>
using namespace std;

//Naive Approach:
/*void sortArray(int arr[], int n, int A, int B, int C){
    for(int i=0;i<n;i++){
        arr[i]=A*arr[i]*arr[i]+B*arr[i]+C;
    }
    sort(arr,arr+n);
}*/

//Optimised approach
void sortArray(int arr[], int n, int A, int B, int C){
// Apply equation on all elements
	for (int i = 0; i < n; i++)
		arr[i] = A*arr[i]*arr[i] + B*arr[i] + C;

	// Find maximum element in resultant array
	int index, maximum = INT_MIN;
	for (int i = 0; i< n; i++){
		if (arr[i] > maximum){
			index = i;
			maximum = arr[i];
		}
	}

	//Use maximum element as a break point and merge both subarrays using merge function of merge sort
	int i = 0, j = n-1;
	int new_arr[n], k = 0;
	while (i < index && j > index){
		if (arr[i] < arr[j])
			new_arr[k++] = arr[i++];
		else
			new_arr[k++] = arr[j--];
	}

	// Merge remaining elements
	while (i < index)
		new_arr[k++] = arr[i++];
	while (j > index)
		new_arr[k++] = arr[j--];

	new_arr[n-1] = maximum;

	// Modify original array
	for (int i = 0; i < n ; i++)
		arr[i] = new_arr[i];
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int A,B,C;
	cin>>A>>B>>C;
	sortArray(arr, n, A, B, C);
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
}

