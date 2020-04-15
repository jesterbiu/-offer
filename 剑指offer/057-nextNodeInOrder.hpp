struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :
        val(x), 
        left(nullptr), 
        right(nullptr), 
        next(nullptr) 
    { }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // validate input 
        if (nullptr == pNode)
        {
            return nullptr;
        }

        // the left subtree of pNode and pNode itself have been visited
        // 1: explored the right subtree of pNode if if exists        
        if (pNode->right != nullptr)
        {
            pNode = pNode->right;
            while (nullptr != pNode->left)
            {
                pNode = pNode->left;
            }
            return pNode;
        }
        
        // 2: if no right subtree exist then search the parent node
        while (pNode->next != nullptr)
        {
            TreeLinkNode* parent = pNode->next;
            // 2.1: if pNode is parent's left so the next node is parent
            if (parent->left == pNode)
            {
                return parent;
            }
            else // 2.2: if pNode is parent's right search the parent's parent
            {
                pNode = parent;
            }
        }
        
        // 3 there is no proper parent node
        return nullptr;
    }
};