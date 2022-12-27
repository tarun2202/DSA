/*	Implementing Dijkstra Algorithm
	Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list 
	of lists containing two integers where the first integer of each list j denotes there is edge between i and j,
	second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the
	shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting
	shortest distance between each node and Source vertex S.
 	Note: The Graph doesn't contain any negative weight cycle
		Input: V = 2 adj [] = {{{1, 9}}, {{0, 9}}}  S = 0
		Output: 0 9
	
	time complexity: O(E.log(v))
	space complexity: O(|e|+|v|)	
*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    // implementing dijkstra' s Algorithm using priority queue
    
    /*vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(V, INT_MAX);

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap and traverse for all its adjacent nodes.
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            //Check for all adjacent nodes of the popped out element whether the prev dist is larger than current or not.
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if (dis + edgeWeight < distTo[adjNode]) {
                    distTo[adjNode] = dis + edgeWeight;
                    // If current distance is smaller, push it into the queue.
                    pq.push({dis + edgeWeight, adjNode});
                }
            }
        }
        // Return the list containing shortest distances from source to all the nodes.
        return distTo;
    }*/
    
    // implementing dijkstra' s Algorithm using Sets
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Create a set ds for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node.
        // set stores the nodes in ascending order of the distances 
        set<pair<int,int>> st; 

        // Initialising dist list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> dist(V, 1e9); 
        
        st.insert({0, S}); 

        // Source initialised with dist=0
        dist[S] = 0;
        
        // Now, erase the minimum distance node first from the set
        // and traverse for all its adjacent nodes.
        while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
            
            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for(auto it : adj[node]) {
                int adjNode = it[0]; 
                int edgW = it[1]; 
                
                if(dis + edgW < dist[adjNode]) {
                    // erase if it was visited previously at 
                    // a greater cost.
                    if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode], adjNode}); 
                        
                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return dist; 
    }
    
};
