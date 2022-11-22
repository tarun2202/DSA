/*	215. Kth Largest Element in an Array
	Given an integer array nums and an integer k, return the kth largest element in the array.
	Note that it is the kth largest element in the sorted order, not the kth distinct element.
		Input: nums = [3,2,1,5,6,4], k = 2
		Output: 5
	
	naive approach--> 	  TC: O(nlogn)	  SC: O(1)
	better Approach-->	  TC: O(n+klogn)  SC: O(k)
	optimised appraoch--> TC: O(n)	      SC: O(n)	
*/

class Solution {
public:
    // naive approach--> TC: O(nlogn)
    /*int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }*/
    
	//Better approach--> using max heap- TC: O(n + k.logn) 
	// O(n): for building max heap   O(klogn): for removing k elements from max heap
    /*int findKthLargest(vector<int>& nums, int k) {
        int ans=0;
        priority_queue<int>pq(nums.begin(), nums.end());
        for(int i=0;i<k;i++){
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }*/
    
    //Optimised approach-->
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[left] ;
        int l = left + 1 ;
        int r = right;
        while (l <= r) {
            if (arr[l] < pivot && arr[r] > pivot) {
                swap(arr[l], arr[r]);
                l++ ;
                r-- ;
            }
            if (arr[l] >= pivot) {
                l++;
            }
            if (arr[r] <= pivot) {
                r--;
            }
        }
        swap(arr[left], arr[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        while(1){
            int idx = partition(nums, left, right);
            if (idx == k - 1) {
                kth = nums[idx];
                break;
            }
            else if (idx < k - 1) 
                left = idx + 1; 
            else
                right = idx - 1;
        }
        return kth; 
    }
};
