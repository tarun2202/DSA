/*	Shortest Path in Weighted undirected graph
	You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there 
	are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if 
	path does not exist then return a list consisting of only -1.
		Input: n = 5, m= 6  edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
		Output: 1 4 3 5
	
	time complexity: O(E+logV)
	space complexity: O(N)	
*/

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int>dist(n+1,INT_MAX), parent(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=i;
        dist[1]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode=it.first;
                int edgeWeight=it.second;
                if(dis+edgeWeight < dist[adjNode]){
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        if(dist[n]==INT_MAX)
            return {-1};
        vector<int>path;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};
