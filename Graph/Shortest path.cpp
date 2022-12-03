/*	Shortest path in Undirected Graph having unit distance
	You are given an Undirected Graph having unit weight, Find the shortest path from src(0) to all the vertex and 
	if it is unreachable to reach any vertex, then return -1 for that vertex.
		Input: n = 9, m= 10, edges=[[0,1],[0,3],[3,4],[4 ,5],[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]]  src=0
		Output: [0 1 2 1 2 3 3 4 4]
	
	time complexity:O(V+E)
	space complexity: O(v)	
*/

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dis(N,-1);
        queue<pair<int,int>>q;
        q.push({src,0});
        dis[src]=0;
        while(!q.empty()){
            int node=q.front().first;
            int w=q.front().second;
            q.pop();
            for(int neighbor:adj[node]){
                if(dis[neighbor]==-1){
                    dis[neighbor]= w+1;
                    q.push({neighbor, w+1});
                }
            }
        }
        return dis;
    }
};
