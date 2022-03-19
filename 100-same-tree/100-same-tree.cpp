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
        // if both are null stay true
        if(p==nullptr && q==nullptr)
        {   ans = true ;return true;}
        // if one is null and another is not null return false
        if(p!=nullptr && q==nullptr || (p==nullptr && q!=nullptr))
        {
            ans = false;
            return false;
        }
        // if both sare not same return false
        if(p->val != q->val)
        {ans = false; return false;}
        // if false don't check further 
        // neither left nor right
        if(ans){
        isSameTree(p->left,q->left);}
        if(ans){
        isSameTree(p->right,q->right);}
        // return ans
        return ans;
        
    }
};