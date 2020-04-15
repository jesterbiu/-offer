#include <vector>
#include <algorithm>
#include <iostream>
// Definition for binary tree
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    void printInOrder(TreeNode* root) 
    {
        if (nullptr == root)
        {
            return;
        }
        printInOrder(root->left);
        std::cout << root->val << " ";
        printInOrder(root->right);

    }
    void printPreOrder(TreeNode* root) 
    {
        if (nullptr == root)
        {
            return;
        }       
        std::cout << root->val << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
    void printTree(const std::vector<int>& pre, const std::vector<int>& in, TreeNode* root)
    {
        std::cout << "pre order: ";
        std::for_each(pre.begin(), pre.end(),
            [](int v) { std::cout << v << " "; });

        std::cout << "\nin order: ";
        std::for_each(in.begin(), in.end(),
            [](int v) { std::cout << v << " "; });

        std::cout << "\nbuilt pre order:";
        printPreOrder(root);

        std::cout << "\nbuilt in order:";
        printInOrder(root);

    }
    void deleteTree(TreeNode* root) 
    {
        if (nullptr == root)
        {
            return;
        }
        if (nullptr != root->left)
        {
            deleteTree(root->left);
        }
        if (nullptr != root->right)
        {
            deleteTree(root->right);
        }
        delete root;
    }
    void testTree() 
    {
        std::vector<int> pre =  { 1, 2, 4, 7, 3, 5, 6, 8 };//;{ 3,9,20,15,7 }
        std::vector<int> in = {4, 7, 2, 1, 5, 3, 8, 6};// ;{ 9,3,15,20,7 }
        TreeNode* root = reConstructBinaryTree(pre, in);
        printTree(pre, in, root);
    }
    TreeNode* reConstructBinaryTree(const std::vector<int>& pre, const std::vector<int>& in) {
        // validate input
        if (pre.empty() || in.empty() || pre.size() != in.size())
        {
            return nullptr;
        }

        
        // partition of left and right subtrees
        auto iterRoot_pre = pre.begin();       
        auto iterRoot_in = std::find(in.begin(), in.end(), *iterRoot_pre);
        if (in.end() == iterRoot_in)
        {
            return nullptr;
        }
        // in-order:
        // left subtree:    [0, root)
        // root:            root
        // right subtree:   [root + 1, size)
        std::vector<int> left_in, right_in;
        if (in.begin() != iterRoot_in)
        {
            left_in.assign(in.begin(), iterRoot_in);
        }
        if (in.end() != iterRoot_in + 1)
        {
            right_in.assign(iterRoot_in + 1, in.end());
        }
        // pre-order:
        // root:            0
        // left subtree:    [1, left_size)     
        // right subtree:   [left_size, size)
        std::vector<int> left_pre, right_pre;
        if (!left_in.empty())
        {
            left_pre.assign(pre.begin() + 1, pre.begin() + 1 + left_in.size());
        }
        if (!right_in.empty())
        {
            right_pre.assign(pre.begin() + 1 + left_in.size(), pre.end());
        }

        // construct current node as a root
        int val = *iterRoot_pre;
        TreeNode* root = new TreeNode(val);

        // construct left and right subtrees recursively as another tree
        root->left = reConstructBinaryTree(left_pre, left_in);
        root->right = reConstructBinaryTree(right_pre, right_in);

        return root;
    }
};