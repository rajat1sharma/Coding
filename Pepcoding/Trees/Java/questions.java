public ArrayList<Node> rootToNodePath(TreeNode node,int data)
{

}



vector<Node> v;
vector<Node> rootToNodePath(TreeNode* node,int data)
{
    if(node==nullptr)
    return v;
    if(node->val==data)
    {
        return true;
    }
    if(rootToNodePath(node->left,data)||rootToNodePath(node-right,data))
    {
        if(rootToNodePath(node->left,data))
        {
            v.push_back(node->left);
            return v;
        }
        else
        {
            v.push_back(node->right);
            return v;
        }
    }
}