struct BSTNode
{
    int data;
    BSTNode *left, *right;
};

class PQ_BST
{
    BSTNode *root;

    BSTNode *insertNode(BSTNode *node, int val)
    {
        if (!node)
            return new BSTNode{val, NULL, NULL};
        if (val > node->data)
            node->right = insertNode(node->right, val);
        else
            node->left = insertNode(node->left, val);
        return node;
    }

    BSTNode *deleteMax(BSTNode *node, int &val)
    {
        if (!node->right)
        {
            val = node->data;
            BSTNode *temp = node->left;
            delete node;
            return temp;
        }
        node->right = deleteMax(node->right, val);
        return node;
    }

public:
    PQ_BST() { root = NULL; }

    void insert(int val)
    {
        root = insertNode(root, val);
    }

    int remove()
    {
        if (!root)
            return -1;
        int val;
        root = deleteMax(root, val);
        return val;
    }
};