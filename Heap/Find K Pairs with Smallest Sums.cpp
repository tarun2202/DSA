/*	373. Find K Pairs with Smallest Sums
	You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
	Define a pair (u, v) which consists of one element from the first array and one element from the second array.
	Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
		Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
		Output: [[1,2],[1,4],[1,6]]
		Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
	
	naive approach-->     TC: O(m*n log(m*n))	SC: O(m*n)
	optimised approach--> TC: O(klogk)			SC: O(k)
*/

vector<int> gv1,gv2;
class Solution {
    public:
    struct cmp{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            return gv1[a.first]+gv2[a.second]>gv1[b.first]+gv2[b.second];
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k){
        gv1=v1,gv2=v2;
        vector<vector<int>> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        map<pair<int,int>,bool> m;
        pq.push({0,0});
        m[{0,0}]=true;
        long long n1=v1.size(),n2=v2.size();
        long long sz=n1*n2;
        while(k-- and sz--){
            pair<int,int> p=pq.top();
            pq.pop();
            ans.push_back({v1[p.first],v2[p.second]});
            int i=p.first,j=p.second;
            if(p.first+1<v1.size() and !m.count({p.first+1,p.second})){
                pq.push({p.first+1,p.second});
                m[{p.first+1,p.second}]=true;
            }
            if(j+1<v2.size() and !m.count({i,j+1})){
                pq.push({i,j+1});
                m[{i,j+1}]=true;
            }
        }
        return ans;
    }
};
