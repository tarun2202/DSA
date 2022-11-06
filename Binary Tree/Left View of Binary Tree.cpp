/*	Left View of Binary Tree
	Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is 
	visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as 
	argument.

	input: 
          1
        /   \
      2      3
    /  \    / \
   4    5  6   7
    \
    8   
    output: [1,2,4,8]
    
    time cpmplexity: O(n)
    space complexity: O(n)
*/

// method 1: level order traversal using queue
/*vector<int> leftView(Node *root) {
    if (!root)
        return {};
    queue<Node*> q;
    q.push(root);
    vector<int>ans;
    while (!q.empty())
    {    
        // number of nodes at current level
        int n = q.size();
         
        // Traverse all nodes of current level
        for(int i = 1; i <= n; i++){
            Node* temp = q.front();
            q.pop();
                 
            // Print the left most element at ith level
            if (i == 1)
                ans.push_back(temp->data);
             
            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);
 
            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return ans;
}*/


//Function to get the left view of the binary tree.
void leftViewUtil(vector<int> &vec, Node *root, int level, int &max_level)
{
    //if root is null, we simply return.
    if (root==NULL)  return;
    
    //if this is the first node of its level then it is in the left view.
    if (max_level < level)
    {
        //storing data of current node in list.
        vec.push_back(root->data);
        max_level = level;
    }
    
    //calling function recursively for left and right subtrees of current node. 
    leftViewUtil(vec,root->left, level+1, max_level);
    leftViewUtil(vec,root->right, level+1, max_level);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    int max_level = -1;
    vector<int> vec;
    leftViewUtil(vec,root, 0, max_level);
    //returning the list.
    return vec;
}
