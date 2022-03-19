/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans =true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)
        {   ans = true ;return true;}
        if(p!=nullptr && q==nullptr || (p==nullptr && q!=nullptr))
        {
            ans = false;
            return false;
        }
        if(p->val != q->val)
        {ans = false; return false;}
        if(ans){
        isSameTree(p->left,q->left);}
        if(ans){
        isSameTree(p->right,q->right);}
        return ans;
        
    }
};