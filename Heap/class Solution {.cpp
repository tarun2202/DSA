/*	973. K Closest Points to Origin
	Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return 
	the k closest points to the origin (0, 0).
	The distance between two points on the X-Y plane is the Euclidean distance (i.e., v(x1 - x2)2 + (y1 - y2)2).
	You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
		Input: points = [[1,3],[-2,2]], k = 1
		Output: [[-2,2]]
	
	naive approach-->     TC: O(nlogn)		SC: O(1)
	optimised approach--> TC: O(n+klogn)	SC: O(k)	
*/

class Solution {
public:
    //method 1: using custom comparator--> takes O(n.logn)
    /*static bool compare(pair<int, int>a, pair<int, int>b){
        int d1 = (a.first * a.first) + (a.second * a.second);
        int d2 = (b.first * b.first) + (b.second * b.second);
        return d1 < d2 ;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       int i , j ;
        vector<pair<int, int>>vec;
        for( i = 0 ; i < points.size() ; i++){
            int x = points[i][0];
            int y = points[i][1];
            vec.push_back({x , y});
        }
        sort(vec.begin() , vec.end() , compare);
        vector<vector<int>>ans;
        for(i = 0 ; i < k ; i++){
           vector<int>p;
            p.push_back(vec[i].first);
            p.push_back(vec[i].second);
            ans.push_back(p);
            p.clear();
        }
        return ans;
    }*/
    
    //method 2: using priorty queue--> takes O(n+ k.logn)
    struct comp{
        bool operator()(vector<int>&p1, vector<int>&p2){
            long d1=p1[0]*p1[0] + p1[1]*p1[1];
            long d2=p2[0]*p2[0] + p2[1]*p2[1];
            return d1>d2;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,comp> pq(points.begin(),points.end());
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            vector<int> p=pq.top();
            ans.push_back(p);
            pq.pop();
        }
        return ans;
    }
};
