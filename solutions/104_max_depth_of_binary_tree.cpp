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
    //return the deepest point in a binary tree recursively
    int maxDepthHelper(TreeNode* node, unsigned int depth){
        if(!(node->left) && !(node->right)){
            return depth;
        }else{
            unsigned int leftTreeDepth = (node->left) ? maxDepthHelper(node->left, depth + 1) : 0;
            unsigned int rightTreeDepth = (node->right) ? maxDepthHelper(node->right, depth + 1) : 0;
            return max(leftTreeDepth, rightTreeDepth);
        }
    }

    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        unsigned int defaultDepth = 2;
        unsigned int leftTreeDepth = (root->left) ? maxDepthHelper(root->left, defaultDepth) : 1;
        unsigned int rightTreeDepth = (root->right) ? maxDepthHelper(root->right, defaultDepth) : 1;
        return std::max(leftTreeDepth, rightTreeDepth);
    }
};