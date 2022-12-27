/*	Bellman-Ford Algorithm
	Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the 
	vertex's from the source vertex S.
	Note: If the Graph contains a negative cycle then return an array consisting of only -1.
		Input: E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]  S = 2
		Output: 1 6 0
		
	time complexity: O(V*E)
	space complexity: O(V)	
*/

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V, 1e8);
        dist[S]=0;
        // Relax all edges |V| - 1 times.
        for(int i=0;i<V;i++){
            for(auto it:edges){
                int u = it[0];
                int v = it[1];
                int wt= it[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v])
                    dist[v]=dist[u]+wt;
            }
        }
        // check for negative weight cycle at the nth 
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e8 && dist[u]+wt < dist[v])
                return {-1};        
        }
        return dist;
    }
};
