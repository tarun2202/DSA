/*	347. Top K Frequent Elements
	Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in 
	any order.	
		Input: nums = [1,1,1,2,2,3], k = 2
		Output: [1,2]
	
	method 1: using hashing and sorting
		TC: O(D.logD + D)	dlogd--> for sortiong and O(d)-- for creating hashmap
		SC: O(D)	
	method 2: using priority queue
		TC:
		SC: 	
*/

//method 1:
/*class Solution {
public:
    // method 1: TC: O(DlogD)   SC: O(D)    D: distinct element in input array
    static bool compare(pair<int,int>&p1, pair<int,int>&p2){
		//If frequencies of two elements are same then the larger number should come first
        if(p1.second==p2.second)
            return p1.first>p2.first;
        //Sort on the basis of decreasing order of frequencies
        return p1.second>p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //implemented as frequency hash table
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        // store the elements of 'mp' in the vector 'freqArr'
        vector<pair<int,int>> freqArr(umap.begin(), umap.end());
        // Sort the vector 'freqArr' on the basis of the compare' function
        sort(freqArr.begin(), freqArr.end(), compare);
        vector<int>ans;
        //storing the top k elements in "ans" vector.
        for(int i=0;i<k;i++){
            ans.push_back(freqArr[i].first);
        }
        return ans;
    }
};*/

//method 2:
class Solution {
public:
    struct compare{
        bool operator()(pair<int,int>&p1, pair<int,int>&p2){
            //If frequencies of two elements are same then the larger number should come first
            if(p1.second==p2.second)
                return p1.first<p2.first;
            // Insert elements in the priority queue on the basis of decreasing order of frequencies
            return p1.second<p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //implemented as frequency hash table
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        // priority queue 'pq' implemented as max heap on the
    // basis of the comparison operator 'compare' element
    // with the highest frequency is the root of 'pq' in
    // case of conflicts, larger element is the root
        priority_queue<pair<int, int>, vector<pair<int, int>>,compare>                                                      pq(mp.begin(), mp.end());
        vector<int>ans;
        for (int i = 1; i <= k; i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
