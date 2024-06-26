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
    // int height(TreeNode* root)
    // {
    //     if(!root)
    //         return 0;
    //     int leftHeight = height(root->left);
    //     int rightHeight = height(root->right);

    //     return 1 + max(leftHeight, rightHeight);
    // }
    // bool isBalanced(TreeNode* root)
    // {
    //     if(!root)
    //         return true;
    //     int leftHeight = height(root->left);
    //     int rightHeight = height(root->right);

    //     if(isBalanced(root->left) && isBalanced(root->right) && abs(leftHeight - rightHeight) <= 1)
    //         return true;
    //     return false;
    // }
    void inorder(TreeNode* root, vector<int> &vec)
    {
        if(root)
        {
            inorder(root->left, vec);
            vec.push_back(root->val);
            inorder(root->right, vec);
        }
    }
    TreeNode* solve(int start, int end, vector<int> &vec)
    {
        if(start>end)
            return NULL;
        TreeNode* newroot;
        if(start==end)
        {
            newroot = new TreeNode(vec[start]);
            return newroot;
        }
        int mid = start + (end - start)/2;
        newroot = new TreeNode(vec[mid]);
        newroot->left = solve(start, mid - 1, vec);
        newroot->right = solve(mid + 1, end, vec);
        return newroot;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // if(isBalanced(root))
        //     return root;
        // TreeNode* newLeft = root->left;
        // TreeNode* newRight = root->right;
        // if(!isBalanced(root->left))
        //     newLeft = balanceBST(root->left);
        // if(!isBalanced(root->right))
        //     newRight = balanceBST(root->right);
        // root->left = newLeft;
        // root->right = newRight;
        // TreeNode* newRoot = root;
        // int leftHeight = height(root->left);
        // int rightHeight = height(root->right);
        // if(leftHeight > rightHeight + 1)
        // {
        //     newRoot = root->left;
        //     TreeNode* temp = newRoot;
        //     while(temp->right)
        //         temp = temp->right;
        //     temp->right = root;
        // }
        // else if(rightHeight > leftHeight + 1)
        // {
        //     newRoot = root->right;
        //     TreeNode* temp = newRoot;
        //     while(temp->left)
        //         temp = temp->left;
        //     temp->left = root;
        // }
        // return balanceBST(newRoot);
        vector<int> vec;
        inorder(root, vec);
        int n = vec.size();
        
        return solve(0, n - 1, vec);
    }
};