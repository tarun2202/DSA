/*	Find Common Nodes in two BSTs
	Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the 
	two BSTs.
		Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9
Output: 4 7 9 10
*/

// naive approach
/*class Solution {
public:
    // Function to find the nodes that are common in both
    // BST.
    set<int> st;
    vector<int> ans;

    void dfs(Node* root)
    {
        if (!root) {
            return;
        }
        st.insert(root->data);
        dfs(root->left);
        dfs(root->right);
    }

    void dfs2(Node* root)
    {
        if (!root) {
            return;
        }
        if (st.find(root->data) != st.end())
            ans.push_back(root->data);
        dfs2(root->left);
        dfs2(root->right);
    }

    vector<int> findCommon(Node* root1, Node* root2)
    {
        dfs(root1);
        dfs2(root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};*/

// optimised approach
class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        //creating two stacks for inorder traversals of both BST.
	    stack<Node *> stack1, s1, s2;
        vector <int> res; 
        
	    while (1)
	    {
	        //pushing the nodes of first BST in stack s1. 
		    if (root1)
		    {
			    s1.push(root1);
			    root1 = root1->left;
		    }
    		//pushing the nodes of second BST in stack s2.
		    else if (root2)
		    {
			    s2.push(root2);
			    root2 = root2->left;
		    }
		    //when both root1 and root2 become NULL
		    else if (!s1.empty() && !s2.empty())
		    {
    			root1 = s1.top();
			    root2 = s2.top();
    			
	    		//if data at current node in two BST's are same, we 
	    		//store it in output list.
		    	if (root1->data== root2->data)
			    {
				    res.push_back (root1->data);
				    //popping element from both stacks.
				    s1.pop();
    				s2.pop();
    				//moving to the inorder successor 
	    			root1 = root1->right;
		    		root2 = root2->right;
			    }
                //if data at current node of first BST is smaller than that of 
                //second BST then it's obvious that inorder successors of 
                //current node can have same value as that of second BST node. 
    			else if (root1->data< root2->data)
	    		{
		    	    //popping element from stack s1.
		    		s1.pop();
			    	root1 = root1->right;
				    
    				//root2 is set to NULL since we need new nodes of first BST. 
		    		root2 = NULL;
			    }
			    else if (root1->data> root2->data)
    			{
    			    //popping element from stack s1.
	    			s2.pop();
		    		root2 = root2->right;
		    		//root1 is set to NULL since we need new nodes of second BST.
			    	root1 = NULL;
    			}
	    	}
	    	else break;
	    } 
	    //returning the output list.
	    return res;
    }
};
