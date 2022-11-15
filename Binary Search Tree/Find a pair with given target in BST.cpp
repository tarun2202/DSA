/*	Find a pair with given target in BST
	Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing 
	up to the target sum.
		Input:
        2
      /   \
     1     3
		sum = 5
		Output: 1 
		Explanation: Nodes with value 2 and 3 sum up to 5.
	
	naive approach--> 	  TC: O(N)	SC: O(N)
	optimised approach--> TC: O(N)	SC: O(H)
*/

// Naive Approach
/*class Solution{
  public:
    void inorder(Node* root,  vector<int>& ans){
        if(root == NULL){
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    int isPairPresent(struct Node *root, int target) {
        vector<int>ans;
        inorder(root, ans);
        int i = 0;
        int j = ans.size()-1;
        while(i < j){
            int sum = ans[i] + ans[j];
            if(sum == target){
                return true;
            }
            else if(sum < target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};*/

// Optimised Approach
class Solution{
  public:    
    bool isPairPresent(Node* root, int target) {
        stack<Node*>s1,s2;
        Node* node= root;
        while(root){
            s1.push(root);
            root=root->left;
        }
        while(node){
            s2.push(node);
            node=node->right;
        }
        while(s1.top()->data != s2.top()->data){
            int x=s1.top()->data, y=s2.top()->data;
            if(x+y==target) return true;
            else if(x+y>target){
                node=s2.top()->left;
                s2.pop();
                while(node){
                    s2.push(node);
                    node=node->right;
                }
            }
            else{
                node=s1.top()->right;
                s1.pop();
                while(node){
                    s1.push(node);
                    node=node->left;
                }
            }
        }
        return false;
    }
};

