/*	Bottom View of Binary Tree
	Given below is a binary tree. The task is to print the bottom view of binary tree. Bottom view of a binary tree is 
	the	set of nodes visible when the tree is viewed from the bottom. 
		input:
        	1
    	  /  \
         2    3
       /  \  / \
      4   5 6   7

	output: [4 2 6 3 7]
	Note: Return nodes from leftmost node to rightmost node.
	
	time complexity: O(n)
	space complexity: O(n)
*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the bottom view from left to right in Binary Tree.
    vector<int> topView(Node *root){
        if(root==NULL)
            return {};
        vector<int>ans;    
        unordered_map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        int minn=INT_MAX, maxx=INT_MIN;
        while(!q.empty()){
            pair<Node*,int>p=q.front();
            q.pop();
            maxx=max(maxx,p.second);
            minn=min(minn,p.second);
            m[p.second]=p.first->data;
            if(p.first->left)
                q.push({p.first->left,p.second-1});
            if(p.first->right)
                q.push({p.first->right,p.second+1});
        }
        for(int i=minn;i<=maxx;i++)
            ans.push_back(m[i]);
        return ans;    
    }
};
