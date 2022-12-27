/*	Minimum Spanning Tree (Prim's Algorithm)
	Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights
	of the edges of the Minimum Spanning Tree.
		Input: 3 3
				0 1 5
				1 2 3
				0 2 1
		Output: 4
		
	time complexity: O(E.logE)
	space complexity: O(V)	
*/

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        vector<int>vis(V,0);
        //PQ: {wt, node}
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(vis[node]==1)
                continue;
            vis[node]=1;    
            sum+=wt;
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edW=it[1];
                if(!vis[adjNode])
                    pq.push({edW, adjNode});
            }
        }
        return sum;
    }
};
