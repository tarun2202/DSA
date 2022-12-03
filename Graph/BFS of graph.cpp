/*	BFS of graph
	Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
	Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph 
	starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or
	indirectly connected from Node 0 in consideration.
		
	time complexity: O(V+E)
	space complexity: O(V)
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> ans;
        bool visted[V]={false};
        q.push(0);
        visted[0]=true;
        while(!q.empty()){
            int temp=q.front();
            ans.push_back(temp);
            q.pop();
            for(int i=0;i<adj[temp].size();i++){
                if(!visted[adj[temp][i]]){
                   visted[adj[temp][i]]=true;
                   q.push(adj[temp][i]);
                }
            }
       }
       return ans;
    }
};
