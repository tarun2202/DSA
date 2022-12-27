/*	Strongly Connected Components (Kosaraju's Algo)
	Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected 
	components in the graph.
	
	Expected Time Complexity: O(V+E).
	Expected Auxiliary Space: O(V).
*/

class Solution
{
    private:
    void dfs(int node, vector<int>adj[], vector<int>& vis, stack<int> &st){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it])
                dfs(it, adj, vis, st);
        }
        st.push(node);
    }
    private:
    void dfsUtil(int node, vector<int>adjT[], vector<int>& vis){
        vis[node]=1;
        for(auto it: adjT[node]){
            if(!vis[it])
                dfsUtil(it, adjT, vis);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(i, adj, vis, st);
        }
        
        vector<int>adjT[V];
        // reverse the edges of graph
        for(int i=0; i<V; i++){
            vis[i]=0;
            for(auto it: adj[i])
                adjT[it].push_back(i);
        }
        
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfsUtil(node, adjT, vis);
            }
        }
        return scc;
    }
};
