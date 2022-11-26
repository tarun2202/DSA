/*	703. Kth Largest Element in a Stream
	Given an input stream arr[] of n integers. Find the Kth largest element for each element in the stream and if the 
	Kth element doesn't exist, return -1.
		Input: k = 4, n = 6		arr[] = {1, 2, 3, 4, 5, 6}
		Output: [-1 -1 -1 1 2 3]
	
	time complexity: O(nlogn)
	space complexity: O(k)	
*/

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
       vector<int>ans;
       priority_queue<int,vector<int>, greater<int>> pq;
       for(int i=0;i<n;i++){
           pq.push(arr[i]);
           if(pq.size() < k)
                ans.push_back(-1);
            else if(pq.size()==k)
                ans.push_back(pq.top());
            else{
                pq.pop();
                ans.push_back(pq.top());
            }    
       }
       return ans;
   }
};
