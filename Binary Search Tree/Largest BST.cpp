/*	Largest BST
	Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
	Note: Here Size is equal to the number of nodes in the subtree.
		Input: 6 6 3 N 2 9 3 N 8 8 2
            6
          /  \
         6    3
         \    / \
         2    9  3
          \  /   \
          8 8     2 
		Output: 2
	
	time complexity: O(N)
	space complexity: O(H)	
*/

struct subTree{
    bool isBST;
    long minm;
    long maxm;
    long cnt;
    subTree(bool flag, long minVal, long maxVal, long cntNode){
        isBST=flag;
        minm=minVal;
        maxm=maxVal;
        cnt=cntNode;
    }
};
class Solution{
    public:
    subTree *getLargestBST(Node *root, long &ans){
        if(root==NULL)
            return new subTree(true, LONG_MAX, LONG_MIN, 0);
        subTree *lst=getLargestBST(root->left, ans);
        subTree *rst=getLargestBST(root->right, ans);
        bool isBST=false;
        long cnt=1+lst->cnt+rst->cnt;
        long minm=min({(long)root->data, lst->minm, rst->minm});
        long maxm=max({(long)root->data, lst->maxm, rst->maxm});
        if(lst->isBST && rst->isBST && root->data>lst->maxm && root->data<rst->minm){
            ans=max(ans,cnt);
            isBST=true;
        }
        return new subTree(isBST, minm, maxm, cnt);
    }
    //You are required to complete this method 
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        long ans=0;
        subTree *ansNode=getLargestBST(root,ans);
        return ans;
    }
};
