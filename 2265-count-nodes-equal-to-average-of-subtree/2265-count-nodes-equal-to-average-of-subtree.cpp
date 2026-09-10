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
    pair<int,int> find(TreeNode* root,unordered_map<TreeNode*,pair<int,int>>& mp){
        if(root==nullptr) return {0,0};
        auto [left_sum, left_node]= find(root->left,mp);
        auto [right_sum, right_node] = find(root->right,mp);
        int sum = left_sum+root->val+right_sum;
        int total_node = left_node+1+right_node;
        mp[root].first = sum;
        mp[root].second = total_node;
        return {sum,total_node};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        unordered_map<TreeNode*,pair<int,int>> mp;
        find(root,mp);
        int ans = 0;
        for(auto& i : mp){
            if(i.first->val == i.second.first/i.second.second) ans++;
        }
        return ans;
    }
};