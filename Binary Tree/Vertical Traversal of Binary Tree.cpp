/*	Vertical Traversal of Binary Tree
	Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
	If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level 
	order traversal of the tree.

	Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
	Output: [4 2 1 5 6 3 8 7 9]	
	
	time complexity: O(n)
	space complexity: O(n) 
*/

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root) {
        // Base case
        if (!root) return {};
  
        // Create a map and store vertical order in map 
        unordered_map<int, vector<int> > m;
        int hd = 0;
  
        // Create queue to do level order traversal Every item of queue contains
        // node and horizontal distance
        queue<pair<Node*, int> > q;
        q.push({root, hd});
    
        // mn and mx contain the minimum and maximum horizontal distance from root
        int mn=0,mx=0;
        while (!q.empty()){
            // pop from queue front
            pair<Node*, int> temp = q.front();
            q.pop();
            hd = temp.second;
            Node* node = temp.first;
  
            // insert this node's data in vector of hash
            m[hd].push_back(node->data);
  
            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        
            // Update mn and mx
            if(hd<mn)
                mn=hd;
            else if(hd>mx)
                mx=hd;
        }
  
        // run the loop from minimum to maximum for every horizontal distance hd
        vector<int>ans;
        for (int i=mn;i<=mx;i++){
            vector<int> tmp=m[i];
            for(int j=0;j<tmp.size();j++)
                ans.push_back(tmp[j]);
        }
        return ans;
    }
};

