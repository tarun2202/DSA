/*	Leaders in an array
	Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader 
	if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 
		Input:	A[] = {16,17,4,3,5,2}
		Output: 17 5 2
		
	naive approach--> TC: O(N^2)	SC: O(N)	
	optimised approach--> TC: O(N)	SC: O(N)
*/

class Solution{
    //Function to find the leaders in the array.
    public:
    //Brute force --> O(n^2)    TC: O(n)
    /*vector<int> leaders(int a[], int n){
        vector<int> ans;
        bool leader;
        for(int i=0; i<n; i++){
            leader = true;
            for(int j=i+1; j<n; j++){
                if(a[j]>a[i]){
                    leader = false;
                    break;
                }
            }
            if(leader == true)
                ans.push_back(a[i]);
        }
        return ans;
    }*/
    
    //optimised approach--> TC: O(N)    SC: O(N)
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        int maxi = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(a[i] >= maxi){
                ans.push_back(a[i]);
                maxi = a[i];//max(maxi, a[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
