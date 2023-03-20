/*	2149. Rearrange Array Elements by Sign
	You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
	You should rearrange the elements of nums such that the modified array follows the given conditions:
	Every consecutive pair of integers have opposite signs.
	For all integers with the same sign, the order in which they were present in nums is preserved.
	The rearranged array begins with a positive integer.
	Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
		Input: nums = [3,1,-2,-5,2,-4]
		Output: [3,-2,1,-5,2,-4]
*/

class Solution {
public:
    //Brute Force approach--> TC: O(N)+O(N/2)   SC: O(N)
    /*vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>pos;
        vector<int>neg; 

        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] < 0)
                neg.push_back(nums[i]);
            else 
                pos.push_back(nums[i]);
        }

        vector<int>answer(n);
        for(int i = 0; i<n/2; i++)
        {
            answer[2*i] = pos[i];
            answer[2*i+1] = neg[i];
        }

        return answer;
    }*/

    //Optimal Approach--> O(N)  SC: O(N)
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posInd = 0;
        int negInd = 1;
        
        vector<int>answer(n, 0);
        for(int i = 0;i<n; i++){
            if(nums[i] < 0) {
                answer[negInd] = nums[i];
                negInd += 2;
            }
            else {
                answer[posInd] = nums[i];
                posInd += 2;
            }
        }
        return answer;
    }
};
