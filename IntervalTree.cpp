#include "IntervalTree.hpp"
#include <iostream>

using namespace std;

IntervalTree::IntervalTree() : root(nullptr) {}

IntervalTree::Node *IntervalTree::insertInterval(Node *node, int low, int high)
{
    if (node == nullptr)
    {
        Node *newNode = new Node(low, high);
        newNode->max_end_point = high;
        return newNode;
    }

    if (low < node->low)
    {
        node->left = insertInterval(node->left, low, high);
    }
    else
    {
        node->right = insertInterval(node->right, low, high);
    }

    node->max_end_point = max(node->max_end_point, high);

    return node;
}

bool IntervalTree::intersection(Node *x, int low, int high)
{
    return !(x->low > high || x->high < low);
}

IntervalTree::Node *IntervalTree::searchInterval(Node *node, int low, int high)
{
    Node *node_to_return = nullptr;
    while (node != nullptr)
    {
        if (intersection(node, low, high))
        {
            if (node_to_return == nullptr || node_to_return->low > node->low)
            {
                node_to_return = node;
            }
        }
        if (node->left == nullptr)
        {
            node = node->right;
        }
        else if (node->left->max_end_point < low)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
    return node_to_return;
}

void IntervalTree::dfs(Node *root)
{
    if (root == nullptr)
        return;
    dfs(root->left);
    dfs(root->right);
    cout << "Node: low = " << root->low << ", high = " << root->high << " max_end_point =" << root->max_end_point << endl;
}

void IntervalTree::insertInterval(int low, int high)
{
    root = insertInterval(root, low, high);
}

void IntervalTree::searchInterval(int low, int high)
{
    Node *nodeResult = searchInterval(root, low, high);

    if (nodeResult != nullptr)
    {
        cout << "Overlapping interval found: [" << nodeResult->low << ", " << nodeResult->high << "]" << endl;
    }
    else
    {
        cout << "No overlapping interval found for [" << low << ", " << high << "]" << endl;
    }
}

void IntervalTree::print()
{
    dfs(root);
}
