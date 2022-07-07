struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == target || original == nullptr) {
            return cloned;
        }
        TreeNode * left = getTargetCopy(original->left, cloned->left, target);
        if(left != nullptr) {
            return left;
        } else {
            return getTargetCopy(original->right, cloned->right, target);
        }
    }
};