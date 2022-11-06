/*	Right View of Binary Tree
	Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.
	input: Right view of following tree is .

          1
        /   \
       2     3
     /  \   / \
    4   5  6   7
    \
     8
    output: [1,3,7,8] 
    
    Method 1: post order traversal using recursion
		time complexity: O(n)
    	space complexity: O(h)
    Method 2: level order traversal using queue
		time complexity: O(n)
    	space complexity: O(w)	
*/

class Solution
{
    public:
    vector<int>ans;

    //method 1: postorder traversal using recursion
    /*void recursion(Node* root, int level, int &maxLevel){
        if(root==NULL)
            return;
        if(level>maxLevel){
            ans.push_back(root->data);
            maxLevel=level;
        }
        recursion(root->right,level+1,maxLevel);
        recursion(root->left,level+1,maxLevel);
    }
    vector<int> rightView(Node *root) {
        int maxLevel=-1;
        recursion(root,0,maxLevel);
        return ans;
    }*/
    
    //method 2: level order traversal using queue
    vector<int> rightView(Node *root) {
        if(root==NULL)
            return {};
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            for(int i=1;i<=len;i++){
                Node* temp=q.front();
                q.pop();
                if(i==1)
                    ans.push_back(temp->data);
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);
            }
        }
        return ans;
    }
    
};
