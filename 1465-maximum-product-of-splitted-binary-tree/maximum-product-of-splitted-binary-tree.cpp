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
private:
    long long MOD = 1000000007;
    long long mx = LLONG_MIN; 
    
    long long getSum(TreeNode* root) {
        if(!root) return 0;
        return getSum(root->left) + getSum(root->right) + root->val;
    }
    
    long long solve(TreeNode* root, long long sum) {
        if(!root) return 0;
        
        long long lt = solve(root->left, sum);
        long long rt = solve(root->right, sum);
        long long curr = (lt + rt + root->val);

        mx = max(mx, curr * (sum - curr));
        
        return curr;
    }
    
public:
    int maxProduct(TreeNode* root) {
        long long sum = getSum(root);
        solve(root, sum);
        return (int)(mx % MOD);
    }
};