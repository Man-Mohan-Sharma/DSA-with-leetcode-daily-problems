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
    int ans = 0;
private:
    pair<int,int> find(TreeNode* root){
        if(root==nullptr) return {0,0};
        auto [left_sum, left_node]= find(root->left);
        auto [right_sum, right_node] = find(root->right);
        int sum = left_sum+root->val+right_sum;
        int total_node = left_node+1+right_node;
        if(sum/total_node == root->val) ans++;
        return {sum,total_node};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        find(root);
        return ans;
    }
};