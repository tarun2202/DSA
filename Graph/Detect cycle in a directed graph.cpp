/*	Detect cycle in a directed graph
	Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
		time complexity: O(V+E)
		space complexity:O(v)
		
*/

class Solution {
  public:
    // DFS algorithm
    /*bool detectCycle(int node, vector<int> adj[], vector<int> &vis){
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
    }*/
    
    //BFS algorithm--> Kahn's Algorithm
    bool isCyclic(int V, vector<int> adj[]) {
		int indegree[V] = {0};
		//finding the incoming edges of each node in given graph
		for (int i = 0; i < V; i++) {
			for (int it : adj[i]) {
				indegree[it]++;
			}
		}
        //pushing the node(s) with in-degree 0  
		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
        //counter to count the nodes in topological sorting    
		int cnt = 0;
		// Kahn's algorithm--> O(v + e)
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cnt++;
			// node is in your topo sort, so remove it from the indegree
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) 
				    q.push(it);
			}
		}
        //checking if no. of nodes in topological sort is equal to no. of vertices of graph
		if (cnt == V) 
		    return false;
		return true;    //if cycle exists
	}
};
