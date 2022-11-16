/*	1305. All Elements in Two Binary Search Trees
	Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted 
	in ascending order.
		Input: root1 = [2,1,4], root2 = [1,0,3]
		Output: [0,1,1,2,3,4]
		
	naive approach--> TC: O((n+m).log(n+m))		SC: O(N+M)
	optimised approach--> TC: O(n+m)			SC: O(N+M)	
*/

// naive approach
/*class Solution
{
public:
     vector<int> res;
     void dfs(TreeNode *root)
     {
          if (!root)
               return;
          res.push_back(root->val);
          dfs(root->left);
          dfs(root->right);
     }
     vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
     {
          dfs(root1);
          dfs(root2);
          sort(begin(res), end(res));
          return res;
     }
};*/

// optimised approach
class Solution {
public:
	//helper funtion to in-order traverse a BST
    void inOrderTraverse(TreeNode *root, vector<int>& vec)
    {
        if(root)
	    {
		    inOrderTraverse(root->left, vec);
		    vec.push_back(root->val);
		    inOrderTraverse(root->right, vec);

	    }
    }
	//helper function to merge two sorted vectors into one sorted vector
    void mergeVectors(vector<int> vec1, vector<int> vec2, vector<int>&                                  mergedVectors) {
        int i = 0, j = 0, k = 0; 
        // Traverse both array 
        while (i < vec1.size() && j < vec2.size()) {        
            if (vec1[i] < vec2[j]) 
                mergedVectors[k++] = vec1[i++]; 
            else
                mergedVectors[k++] = vec2[j++]; 
        }    
        while (i < vec1.size()) 
            mergedVectors[k++] = vec1[i++]; 
 
        while (j < vec2.size()) 
            mergedVectors[k++] = vec2[j++]; 
    } 
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1, tree2;
		//in-order traverse both trees, now tree1 has 1st tree's elements sorted            and tree2 has 2nd tree's elements sorted
        inOrderTraverse(root1, tree1);
        inOrderTraverse(root2, tree2);
        
        vector<int> mergedVectors(tree1.size() + tree2.size());
		//merge tree1 and tree2 into one merged sorted vector
        mergeVectors(tree1, tree2, mergedVectors);
        
        return  mergedVectors;
    }
};
