/* 	Alternate positive and negative numbers
	Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
	Note: Array should start with a positive number.
		Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
		Output:	9 -2 4 -1 5 -5 0 -3 2
	
	time complexity: O(n)+ min(sizeof(pos, neg)) + O(leftover)	~ O(2n)
	space complexity: O(n)
*/

//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> pos, neg;
	    for(int i=0; i<n; i++){
	        if(arr[i]>=0)
	            pos.push_back(arr[i]);
	         else
	            neg.push_back(arr[i]);
	    }
	    
	    if(pos.size() > neg.size()){
	        for(int i=0; i<neg.size(); i++){
	            arr[2*i] = pos[i];
	            arr[2*i+1] = neg[i];
	        }
	        int index = neg.size()*2;
	        for(int i=neg.size(); i<pos.size(); i++){
	            arr[index]= pos[i];
	            index++;
	        }
	    }
	    else{
	        for(int i=0; i<pos.size(); i++){
	            arr[2*i] = pos[i];
	            arr[2*i+1] = neg[i];
	        }
	        int index = pos.size()*2;
	        for(int i=pos.size(); i<neg.size(); i++){
	            arr[index] = neg[i];
	            index++;
	        }
	    }
	}
};	
