#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    explicit Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

int closestValueIterative(Node *root, int x)
{
    if (root == nullptr)
    {
        throw invalid_argument("BST is empty");
    }

    int closest = root->value;
    Node *current = root;

    while (current != nullptr)
    {
        if (abs(current->value - x) < abs(closest - x))
        {
            closest = current->value;
        }

        if (x < current->value)
        {
            current = current->left;
        }
        else if (x > current->value)
        {
            current = current->right;
        }
        else
        {
            return current->value;
        }
    }

    return closest;
}

void closestValueRecursiveHelper(Node *root, int x, int &closest)
{
    if (root == nullptr)
    {
        return;
    }

    if (abs(root->value - x) < abs(closest - x))
    {
        closest = root->value;
    }

    if (x < root->value)
    {
        closestValueRecursiveHelper(root->left, x, closest);
    }
    else if (x > root->value)
    {
        closestValueRecursiveHelper(root->right, x, closest);
    }
}

int closestValueRecursive(Node *root, int x)
{
    if (root == nullptr)
    {
        throw invalid_argument("BST is empty");
    }

    int closest = root->value;
    closestValueRecursiveHelper(root, x, closest);
    return closest;
}

void deleteTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    vector<int> values = {2, 5, 9, 12, 18};
    Node *root = nullptr;

    for (int v : values)
    {
        root = insert(root, v);
    }

    int x1 = 10;
    int x2 = 13;

    cout << "BST Elements: {2, 5, 9, 12, 18}" << endl;
    cout << "Input: X = " << x1 << endl;
    cout << "Closest value (iterative) = " << closestValueIterative(root, x1) << endl;
    cout << "Closest value (recursive) = " << closestValueRecursive(root, x1) << endl;

    cout << endl;

    cout << "Input: X = " << x2 << endl;
    cout << "Closest value (iterative) = " << closestValueIterative(root, x2) << endl;
    cout << "Closest value (recursive) = " << closestValueRecursive(root, x2) << endl;

    deleteTree(root);
    return 0;
}
