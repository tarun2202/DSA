/*	Detect cycle in a directed graph
	Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
		
	Time Complexity: O(V+E)
	Space Complexity: O(V)
*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    /*bool isCyclic(int V, vector<int> adj[]) {
        // code here
    }*/
    
    bool detectCycle(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto adjacentNode : adj[node]){
            if(vis[adjacentNode]==2)
                continue;
            if(vis[adjacentNode]==1)
                return true;
            if(detectCycle(adjacentNode, adj, vis))
                return true;
        }
        vis[node]=2;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]){
        vector<int>vis(V,0);
        for(int i=0;i<V; i++){
            if(!vis[i]){
                if(detectCycle(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};
