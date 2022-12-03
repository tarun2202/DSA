/*	DFS of Graph
	You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
	Note: Use a recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.
		
		Time complexity: O(V+2E)
		Space conplexity: O(V)
*/

class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int>&ls){
        vis[node]=1;
        ls.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]])
                dfs(adj[node][i], adj, vis, ls);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int>ls;
        int vis[v]={0};
        for(int i=0;i<v;i++){
            if(!vis[i])
                dfs(i, adj, vis, ls);
        }        
        return ls;
    }
};
