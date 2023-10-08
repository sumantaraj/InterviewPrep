/*
Problem : Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            if (root == NULL) return res;
    
            queue<TreeNode*> q;
            q.push(root);
    
            while (!q.empty()) {
                int levelSize = q.size();
                vector<int> levelValues;
    
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = q.front();
                    q.pop();
    
                    if (node->left != NULL) q.push(node->left);
                    if (node->right != NULL) q.push(node->right);
    
                    levelValues.push_back(node->val);
                }
    
                res.push_back(levelValues);
            }
    
            return res;
        }
    };

    /*Python solution ::after
    def levelOrder(self, root):
    if not root:
        return []
    ans, level = [], [root]
    while level:
        ans.append([node.val for node in level])
        temp = []
        for node in level:
            temp.extend([node.left, node.right])
        level = [leaf for leaf in temp if leaf]
    return ans */
