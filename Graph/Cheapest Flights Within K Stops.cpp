/*	787. Cheapest Flights Within K Stops
	There are n cities and m edges connected by some number of flights. You are given an array flights where 
	flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
	You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k 
	stops. If there is no such route, return -1.
		Input: n = 4 flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]] src = 0 dst = 3 k = 1
		Output:	700
	
	time complexity: O(E)
	space complexity: O(E+N)	
*/

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // creating the adjacency list
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it: flights)
            adj[it[0]].push_back({it[1],it[2]});
        vector<int>dist(n,1e9);
        dist[src]=0;
        // queue: {stops,{node,cost}}
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            // when stops exceed K: don't consider the current path 
            if(stops > K)    continue;
            // traverse over the adjacent node to find the cheapest flight within K stops
            for(auto &it: adj[node]){
                int adjNode=it.first;
                int edW=it.second;
                if(cost+edW < dist[adjNode] && stops<=K){
                    dist[adjNode] = cost+edW;
                    q.push({stops+1, {adjNode,cost+edW}});
                }
            }
        }
        //when no path is there to reach from source to destination: return -1
        if(dist[dst]==1e9)  return -1;
        return dist[dst];
    }
};
