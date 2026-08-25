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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> ans;
        while(!qu.empty()){
            vector<int> cur;
            int s = qu.size();
            for(int i = 1; i<=s; i++){
                TreeNode* temp = qu.front();
                qu.pop();
                cur.push_back(temp->val);
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};