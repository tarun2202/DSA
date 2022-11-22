/*	Merge k Sorted Arrays
	Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
		Input: K = 3 arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
		Output: 1 2 3 4 5 6 7 8 9
		
	Naive approach--> 	  TC: O(K^2.logk)	SC: O(k^2)
	Optimised approach--> TC: O(K^2.logk)	SC: O(k)	
*/

// naive approach--> 
/*class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K){
        vector <int>v;
        for(int i=0;i<K;i++)
            for(int j=0;j<K;j++)
                v.push_back(arr[i][j]);
    
        sort(v.begin(),v.end());
        return v;
    }
};*/


// optimised approach
vector<vector<int>> arr1;
class Solution
{
public:
    // Function to merge k sorted arrays.
    struct cmp
    {
        bool operator()(pair<int, int> &p1, pair<int, int> &p2){
            int v1 = arr1[p1.first][p1.second];
            int v2 = arr1[p2.first][p2.second];
            return v1 > v2;
       }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        arr1.resize(arr.size(), vector<int>(arr[0].size()));
        for (int i = 0; i < arr.size(); i++)
             for (int j = 0; j < arr[0].size(); j++)
                 arr1[i][j] = arr[i][j];
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (int i = 0; i < k; i++)
           q.push({i, 0});
        vector<int> ans;
        while (!q.empty()) {
            pair<int, int> v = q.top();
            q.pop();
            int i = v.first;
            int j = v.second;
            ans.push_back(arr1[i][j]);
            if (j + 1 < k)
                q.push({i, j + 1});
        }
        return ans;
    }
};
