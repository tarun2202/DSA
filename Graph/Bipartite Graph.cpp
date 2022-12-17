/*	Bipartite Graph
	Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is 
	bipartite or not.
	
		Time Complexity: O(V + E)
		Space Complexity: O(V)
*/

class Solution {
public:
    //BFS Solution
    /*bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (colors[i]) continue;
            
            colors[i] = 1;
            q.push(i);
            
            while (!q.empty()) {
                int temp = q.front();
                
                for (auto neighbor : graph[temp]) {
                    
					// Color neighbor with opposite color
                    if (!colors[neighbor]){
                        colors[neighbor] = -colors[temp];
                        q.push(neighbor);
                    }
                    
					// If the neighbor has the same color - can't bipartite.
                    else if (colors[neighbor] == colors[temp]) 
                        return false;
                }
                q.pop();
            }
        }
        return true;
    }*/

    //DFS solution
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int curr, int col){
        color[curr]=col;
        for(int i=0;i<graph[curr].size();i++){
            int next=graph[curr][i];
            //when two adjacent nodes have same color: not bipartite
            if(color[curr] == color[next])
                return false;
            // when node is unvisited: traverse for adjacent node    
            if(color[next] == -1)
                if(dfs(graph,color,next,!col)==false)
                    return false;
        }
        // the given graph is bipartite
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n; i++){
            if(color[i]==-1)
                if(dfs(graph,color,i,0)==false)
                    return false;
        }
        return true;
    }
};
