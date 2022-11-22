/*	Kth smallest element
	Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest 
	element in the given array. It is given that all array elements are distinct.
		Input: N = 6  arr[] = 7 10 4 3 20 15  K = 3
		Output : 7
	
	naive approach--> 	  TC: O(nlogn)	  SC: O(1)
	better Approach-->	  TC: O(n+klogn)  SC: O(k)
	optimised appraoch--> TC: O(n)	      SC: O(n)		
*/

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    // Naive approach--> O(nlogn)
    /*int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr, arr+r+1);
        return arr[k-1];
    }*/
    
    //better approach--> O(n+klogn)
   int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int, vector<int>, greater<int>>pq(arr, arr+r+1);
        int ans=0;
        for(int i=0;i<k-1;i++){
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};
