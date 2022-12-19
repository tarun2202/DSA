/*	Detect cycle in an undirected graph
	Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
		Input: V = 5, E = 5  adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
		Output: 1
	
	time complexity: O(V+E)
	space complexity: O(V)
*/

class Solution {
  public:
    //DFS traversal
    /*bool dfs(int currNode, int prevNode, vector<int>adj[], vector<bool>&vis){
        vis[currNode] = true;
        for(int i=0; i<adj[currNode].size(); i++){
            if(adj[currNode][i] == prevNode) 
                continue;
            if(vis[adj[currNode][i]]) 
                return true;
            if(dfs(adj[currNode][i], currNode, adj, vis)) 
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]){
        vector<bool>visited(V, false);
        int prevNode = -1;
        for(int currNode = 0; currNode < V; currNode++){
            if(!visited[currNode]){
                bool hasCycle = dfs(currNode, prevNode, adj, visited);
                if(hasCycle) 
                    return true;
            }
        }
        return false;
    }*/
    
    //BFS traversal
    bool detectCycle(int src, vector<int> adj[], vector<bool> &vis){
        vis[src]=true;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent= q.front().second;
            q.pop();
            for(auto adjacentNode : adj[node]){
                if(vis[adjacentNode]==false){
                    vis[adjacentNode]=true;
                    q.push({adjacentNode, node});
                }
                else if(parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]){
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i])
                if(detectCycle(i, adj, vis))
                    return true;
        }
        return false;
    }
};
