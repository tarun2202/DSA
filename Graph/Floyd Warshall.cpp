/*	Floyd Warshall
	The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed 
	graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge 
	from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
	Do it in-place.
		Input: matrix = {{0,25},{-1,0}}
		Output: {{0,25},{-1,0}}
	
	time complexity: O(N^3)	
	space complexity: O(N^2)	//as we are using the given matrix as our adjacency matrix to find the final answer.
*/

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            //if no edge from node i to node j
	            if(matrix[i][j] == -1) 
	                matrix[i][j] = 1e9; // set to infinity means not reachable from node i to node j
	            // dist to reach from node i to node i(reaching itself) is always 0.
	            if(i==j)    
	                matrix[i][j] = 0;
	        }
	    }
	    
	    //finding the shortest distance from node i to node j via node k for all pair of nodes
	    for(int k=0; k<n; k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);	            }
	        }
	    }
	    
	    // setting the distance from where node i is not reachable to node j: setting it as -1. 
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9)
	                matrix[i][j] = -1;
	        }
	    }
	}
};
