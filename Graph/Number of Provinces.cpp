/*	Number of Provinces
	Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a 
	path from u to v or v to u. Your task is to find the number of provinces.
	
		Time Complexity: O(V2)
		Space Complexity: O(V)
*/

class Solution {
public:
    void dfs(int node, vector<int>adj[], vector<int> &vis){
        vis[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]])
                dfs(adj[node][i], adj, vis);
        }
    }
    int numProvinces(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int>adj[v];
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(v,0);
        int ans=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                ans++;
                dfs(i, adj, vis);  
            }
        }
        return ans;
    }
};
