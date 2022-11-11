/*	297. Serialize and Deserialize Binary Tree
	
	
	time cpmplexity: O(n)
	space complexity: O(n)
*/

// leetcode Template
class Codec {
public:

    // Encodes a tree to a single string using level order traversal
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)
                s.append("#,");
            else
                s.append(to_string(curr->val)+',');
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);    
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) 
            return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }
};

// GFG  template
/*
class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto temp = q.front();
                q.pop();
                if(temp == NULL){
                    ans.push_back(-1);
                    continue;
                }
                ans.push_back(temp->data);
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       if(A.size() == 0) return NULL;
       Node* root = new Node(A[0]);
       queue<Node*>q;
       q.push(root);
       int i = 1;
       while(!q.empty()){
           Node* temp = q.front();
           q.pop();
           // left
           if(A[i] == -1){
               temp->left = NULL;
           }
           else{
               temp->left = new Node(A[i]);
               q.push(temp->left);
           }
           // right
           if(A[i+1] == -1){
               temp->right = NULL;
           }
           else{
               temp->right = new Node(A[i+1]);
               q.push(temp->right);
           }
           i+=2;
       }
       return root;
    }
};*/
