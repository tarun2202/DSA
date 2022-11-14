/*	Kth largest element in BST
	Given a Binary search tree. Your task is to complete the function which will return the Kth largest element 
	without doing any modification in Binary Search Tree.
		Input:
      			4
    		  /   \
             2     9
			k = 2 
		Output: 4
	
	naive approach--> 		TC: O(nlogn)	SC: O(N)
	better appraoch--> 		TC: O(N)	SC: O(N)
	optimised approach-->   TC: O(N)	SC: O(1)	
*/

class Solution
{
    public:
    void traverseBST(Node* root, int K , int &count, int &ans){
        if(!root)
            return;
        traverseBST(root->right, K, count, ans);
        count++;
        if(count==K){
            ans=root->data;
            return;
        }
        traverseBST(root->left, K, count, ans);
    }
    int kthLargest(Node *root, int K)
    {
        int count=0, ans=-1;
        traverseBST(root, K, count, ans);
        return ans;
    }
};
