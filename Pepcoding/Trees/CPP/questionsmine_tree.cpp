#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} 
};


 int size(TreeNode* root)
 {
     return root==nullptr?0:size(root->left)+size(root->right)+1;
 }


//height in terms of nodes
 int height(TreeNode* root)
 {
     return root==nullptr?0:max(height(root->left),height(root->right))+1;
 }



//height in terms of edges
 int height(TreeNode* root)
 {
     return root==nullptr?-1:max(height(root->left),height(root->right))+1;
 }


int maximum(TreeNode* root)
{
    if(root==nullptr)
    return -1e9;
    int l_max=maximum(root->left);
    int r_max=maximum(root->right);

    return max(l_max,max(r_max,root->val));
    
}
// will not check the right subtree if found in left subtree [find(root->left,data)]
bool find(TreeNode* root, int data)
{
    if(root==nullptr)
    return false;
    if(root->val==data)
    return true;
    return find(root->left,data)||find(root->right,data);
}

//root to node path
    bool path(TreeNode* root,TreeNode* data,vector<TreeNode*>& v)
    {
        if(root==nullptr)
            return false;
        if(root->val==data->val)
        {v.push_back(root);
            return true;}
        bool res=path(root->left,data,v)||path(root->right,data,v);
        if(res)
            v.push_back(root);
        return res;
    }

    //returning vector instead of passing vector in the function
 vector<TreeNode*> path2(TreeNode* root,TreeNode* data)
    {
        vector<TreeNode*> v;
            
        if(root==nullptr)
        {       
            return v;
        }
        if(root->val==data->val)
        {
            vector<TreeNode*> v;
            v.push_back(root);
                return v;
        }
        vector<TreeNode*> left=path2(root->left,data);
        if(left.size()>0)
        {
            left.push_back(root->left);
            return left;
        }
        
        vector<TreeNode*> right=path2(root->right,data);
        if(right.size()>0)
        {
            right.push_back(root->right);
            return right;
        }
        return v;
    }
//236 lca
//mistakes - pass vector by reference in path function
//logic- implement path function by passing a vector with reference and then find that node before the first dissimilar node in both vectors

 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {   
        vector<TreeNode*> v1,v2;
        path(root,p,v1);
        path(root,q,v2);
        int i=v1.size()-1;
        int j=v2.size()-1;
        TreeNode* ans;
        
        while(i>=0&&j>=0)
        {
            
            if(v1[i]!=v2[j])
            {
                break;
            }
            ans=v1[i];
            i--;
            j--;
        }
        return ans;
    }



