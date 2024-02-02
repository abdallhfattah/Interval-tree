#ifndef INTERVAL_TREE_HPP
#define INTERVAL_TREE_HPP

#include <string>
#include <iostream>

class IntervalTree
{
private:
    class Node
    {
    public:
        int low;
        int high;
        int max_end_point;
        Node *left;
        Node *right;

        Node(int l, int h) : low(l), high(h), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node *insertInterval(Node *node, int low, int high);
    bool intersection(Node *x, int low, int high);
    Node *searchIntervalPrivate(Node *node, int low, int high);
    void dfs(Node *root);

public:
    IntervalTree();
    void insertInterval(int low, int high);
    std::string searchInterval(int low, int high);
    void print();
};

#endif // INTERVAL_TREE_HPP
