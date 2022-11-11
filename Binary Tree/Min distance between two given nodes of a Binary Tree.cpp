/*	Min distance between two given nodes of a Binary Tree
	Given a binary tree and two node values your task is to find the minimum distance between them.
	The given two nodes are guaranteed to be in the binary tree and nodes are numbered from 1 to N.
	Please Note that a and b are not always leaf node.
		Input:
        1
      /  \
     2    3
		a = 2, b = 3
		Output: 2
		
	time complexity: O(N)
	space complexity: O(N)	
*/

class Solution{
    public:
    // Should return minimum distance between a and b in a tree with given root*/
//steps 1 : find lca of a and b
//step 2: find distance of a from lca node and b from lca node
//step 3: return sum of both distance
    Node *lca(Node *root,int a ,int b){
        if(!root || root->data==a || root->data==b)
            return root;
        Node *left = lca(root->left,a,b);
        Node *right = lca(root->right,a,b);
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
            return root;
    }
    void dist(Node *root, int node, int cnt, int &res){
        if(root==NULL)
            return ;
        if(root->data == node){
            res=cnt;
            return;
        }
        dist(root->left, node, cnt+1, res);
        dist(root->right, node, cnt+1, res);
    }
    int findDist(Node* root, int a, int b) {
        if(!root) //empty tree
            return 0;
        if(root->data == a && root->data == b)	// only 1 node in BT
            return 0;
        //finding the lowest common ancestor    
        Node *curr = lca(root,a,b);
        int x = 0;
        dist(curr,a,0,x);
        int y = 0;
        dist(curr,b,0,y);
        return x+y;
    }
};
