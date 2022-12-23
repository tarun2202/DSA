/*	802. Find Eventual Safe States
	There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed
	2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from 
	node i to each node in graph[i].
	A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting 
	from that node leads to a terminal node (or another safe node).
	Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
		
		time complexity:O(V+E)
		space complexity:O(V)
*/

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		vector<int> adjRev[V];
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			// i -> it
			// it -> i
			for (auto it : adj[i]) {
				adjRev[it].push_back(i);
				indegree[i]++;
			}
		}
		queue<int> q;
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			safeNodes.push_back(node);
			for (auto it : adjRev[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		sort(safeNodes.begin(), safeNodes.end());
		return safeNodes;
	}
};

