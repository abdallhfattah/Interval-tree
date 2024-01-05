#include <iostream>

using namespace std;

#define SEPERATOR cout << "---------------------\n";
#define TEST "Test Case "
#define INT_MAX 1e9
#define INT_MIN -INT_MAX

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

    class Interval
    {
    public:
        int low;
        int high;
    };

    Node *root;

    Node *insertInterval(Node *node, int low, int high)
    {
        if (node == nullptr)
        {
            Node *newNode = new Node(low, high);
            newNode->max_end_point = high;
            return newNode;
        }

        // Perform standard BST insertion
        if (low < node->low)
        {
            node->left = insertInterval(node->left, low, high);
        }
        else
        {
            node->right = insertInterval(node->right, low, high);
        }

        // Update high value for this node
        node->max_end_point = max(node->max_end_point, high);

        return node;
    }
    bool intersection(Node *x, int low, int high)
    {

        /*
            case :
         x       -------
         l,h --- 
         or 
         x    -------
                    l,h  ------  
        */
        return !(x->low > high  || x->high < low);
        // // case 1
        // /*
        // x=   1 ---- 5
        //         3 ---- 6
        // */
        // if (x->low < low && x->high > low)
        //     return true;

        // // case 2
        // /*
        //  x =   4 ---- 18
        //     1 --- 5
        // */
        // if (x->low < high && high <= x->high)
        // {
        //     return true;
        // }

        // // case 3 = case2
        // /*
        // x =  1 ------------ 20
        //          5 --- 9
        // */

        // // case 4
        // /*
        // x =     5  --- 9
        //      1 ------------- 20
        // */
        // if (low <= x->low && x->high <= high)
        // {
        //     return true;
        // }

        // return false;
    }

    Node *searchInterval(Node *node, int low, int high)
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

    void dfs(Node *root)
    {
        if (root == nullptr)
            return;

        dfs(root->left);
        dfs(root->right);
        cout << "Node: low = " << root->low << ", high = " << root->high << " max_end_point =" << root->max_end_point << endl;
    }

public:
    IntervalTree() : root(nullptr) {}

    // Method to insert an interval into the tree
    void insertInterval(int low, int high)
    {
        root = insertInterval(root, low, high);
    }

    // Method to search for an interval that overlaps with the given query interval
    void searchInterval(int low, int high)
    {
        Node *nodeResult = searchInterval(root, low, high);

        if (nodeResult != nullptr)
        {
            cout << "Overlapping interval found: [" << nodeResult->low << ", " << nodeResult->high << "]" << endl;
        }
        else
        {
            // No overlapping interval found
            cout << "No overlapping interval found for [" << low << ", " << high << "]" << endl;
        }
    }

    void print()
    {
        dfs(root);
    }

    void printRoot()
    {
        cout << "ROOOOOOOT\n";
        cout << "Node: low = " << root->low << ", high = " << root->high << " max_end_point =" << root->max_end_point << endl;
        cout << "\n\n\n";
    }
};
int main()
{
    IntervalTree intervalTree;

    // Test Case 1: No overlapping intervals`
    cout << TEST << " 1\n";

    intervalTree.insertInterval(17, 19);
    intervalTree.insertInterval(5, 8);
    intervalTree.insertInterval(21, 24);
    intervalTree.insertInterval(15, 18);
    intervalTree.insertInterval(16, 22);
    intervalTree.insertInterval(7, 10);
    intervalTree.insertInterval(4, 8);
    intervalTree.searchInterval(25, 83);
    SEPERATOR

    // Test Case 2: Overlapping interval found
    cout << TEST << " 2\n";
    intervalTree.insertInterval(35, 40);
    intervalTree.insertInterval(45, 50);
    intervalTree.searchInterval(42, 48);
    SEPERATOR

    // Test Case 3: Overlapping interval found (right child)
    cout << TEST << " 3\n";
    intervalTree.insertInterval(55, 60);
    intervalTree.insertInterval(65, 70);
    intervalTree.searchInterval(68, 75); // Expect: Found overlapping interval: [65, 70]
    SEPERATOR

    // Test Case 4: Overlapping interval found (left child)
    cout << TEST << " 4\n";
    intervalTree.insertInterval(75, 80);
    intervalTree.insertInterval(85, 90);
    intervalTree.searchInterval(78, 82); // Expect: Found overlapping interval: [75, 90]
    SEPERATOR

    // Test Case 5: Overlapping interval found (overlapping both children)
    cout << TEST << " 5\n";
    intervalTree.insertInterval(95, 100);
    intervalTree.insertInterval(105, 110);
    intervalTree.searchInterval(98, 108); // Expect: Found overlapping interval: [95, 110]
    SEPERATOR

    // Test Case 6: Query interval is fully contained in one interval
    cout << TEST << " 6\n";
    intervalTree.insertInterval(115, 120);
    intervalTree.insertInterval(125, 130);
    intervalTree.searchInterval(118, 122); // Expect: Found overlapping interval: [115, 120]
    SEPERATOR

    // Test Case 7: Query interval is fully contained in multiple intervals
    cout << TEST << " 7\n";
    intervalTree.insertInterval(135, 140);
    intervalTree.insertInterval(145, 150);
    intervalTree.insertInterval(155, 160);
    intervalTree.searchInterval(142, 148); // Expect: Found overlapping interval: [135, 160]
    SEPERATOR

    // Test Case 8: Query interval overlaps with the root's right child
    cout << TEST << " 8\n";
    intervalTree.searchInterval(100, 105); // Expect: Found overlapping interval: [95, 110]
    SEPERATOR

    // Test Case 9: Query interval overlaps with the root's left child
    cout << TEST << " 9\n";
    intervalTree.searchInterval(10, 18); // Expect: Found overlapping interval: [5, 20]
    SEPERATOR

    // Test Case 10: Query interval is fully contained in the root
    cout << TEST << " 10\n";
    intervalTree.searchInterval(65, 70); // Expect: Found overlapping interval: [65, 70]
    SEPERATOR

    // Test Case 11: Query interval is not found
    cout << TEST << " 11\n";
    intervalTree.searchInterval(200, 210); // Expect: No overlapping interval found
    SEPERATOR

    // Test Case 12: Overlapping intervals with negative values
    cout << TEST << " 12\n";
    intervalTree.insertInterval(-10, -5);
    intervalTree.insertInterval(-20, -15);
    intervalTree.insertInterval(-30, -25);
    intervalTree.searchInterval(-18, -12); // Expect: Found overlapping interval: [-20, -5]
    SEPERATOR

    // Test Case 13: Overlapping intervals with zero
    cout << TEST << " 13\n";
    intervalTree.insertInterval(0, 5);
    intervalTree.insertInterval(10, 15);
    intervalTree.searchInterval(2, 8); // Expect: Found overlapping interval: [0, 15]
    SEPERATOR

    // Test Case 14: Large values
    cout << TEST << " 14\n";
    intervalTree.insertInterval(1000, 1010);
    intervalTree.insertInterval(1020, 1030);
    intervalTree.searchInterval(1005, 1025); // Expect: Found overlapping interval: [1000, 1030]
    SEPERATOR

    // Test Case 15: Large number of intervals
    cout << TEST << " 15\n";
    for (int i = 2000; i <= 2050; i += 5)
    {
        intervalTree.insertInterval(i, i + 3);
    }
    intervalTree.searchInterval(2035, 2045); // Expect: Found overlapping interval: [2030, 2053]
    SEPERATOR

    // Test Case 16: Query interval with negative values
    cout << TEST << " 16\n";
    intervalTree.searchInterval(-15, -10); // Expect: Found overlapping interval: [-20, -5]
    SEPERATOR

    // Test Case 17: Query interval with large values
    cout << TEST << " 17\n";
    intervalTree.searchInterval(3000, 3010); // Expect: No overlapping interval found
    SEPERATOR

    // Test Case 18: Query interval with zero
    cout << TEST << " 18\n";
    intervalTree.searchInterval(0, 3); // Expect: Found overlapping interval: [-20, 15]
    SEPERATOR

    // Test Case 19: Single interval
    cout << TEST << " 19\n";
    IntervalTree singleIntervalTree;
    singleIntervalTree.insertInterval(50, 60);
    singleIntervalTree.searchInterval(55, 57); // Expect: Found overlapping interval: [50, 60]
    SEPERATOR

    // Test Case 20: Single interval, query outside the interval
    cout << TEST << " 20\n";
    singleIntervalTree.searchInterval(70, 80); // Expect: No overlapping interval found
    SEPERATOR

    // Test Case 21: Single interval, query with negative values
    cout << TEST << " 21\n";
    singleIntervalTree.searchInterval(45, 48); // Expect: No overlapping interval found
    SEPERATOR

    // Test Case 22: Single interval, query with large values
    cout << TEST << " 22\n";
    singleIntervalTree.searchInterval(100, 110); // Expect: No overlapping interval found
    SEPERATOR

    // Test Case 23: Empty tree
    cout << TEST << " 23\n";
    IntervalTree emptyTree;
    emptyTree.searchInterval(5, 10); // Expect: No overlapping interval found
    SEPERATOR

    // Test Case 24: Overlapping intervals with same low and high values
    cout << TEST << " 24\n";
    IntervalTree sameLowHighTree;
    sameLowHighTree.insertInterval(10, 20);
    sameLowHighTree.insertInterval(20, 30);
    sameLowHighTree.insertInterval(30, 40);
    sameLowHighTree.searchInterval(18, 22); // Expect: Found overlapping interval: [10, 30]
    SEPERATOR

    // Test Case 25: Query interval with same low and high values
    cout << TEST << " 25\n";
    sameLowHighTree.searchInterval(30, 30); // Expect: Found overlapping interval: [10, 40]
    SEPERATOR

    // Test Case 26: Overlapping intervals with one containing another
    cout << TEST << " 26\n";
    IntervalTree containingIntervalsTree;
    containingIntervalsTree.insertInterval(5, 15);
    containingIntervalsTree.insertInterval(10, 12);
    containingIntervalsTree.searchInterval(8, 14); // Expect: Found overlapping interval: [5, 15]
    SEPERATOR

    // Test Case 27: Overlapping intervals with one contained within another
    cout << TEST << " 27\n";
    IntervalTree containedIntervalsTree;
    containedIntervalsTree.insertInterval(30, 40);
    containedIntervalsTree.insertInterval(35, 37);
    containedIntervalsTree.searchInterval(32, 38); // Expect: Found overlapping interval: [30, 40]
    SEPERATOR

    // Test Case 28: Overlapping intervals with equal intervals
    cout << TEST << " 28\n";
    IntervalTree equalIntervalsTree;
    equalIntervalsTree.insertInterval(5, 10);
    equalIntervalsTree.insertInterval(5, 10);
    equalIntervalsTree.insertInterval(5, 10);
    equalIntervalsTree.searchInterval(6, 8); // Expect: Found overlapping interval: [5, 10]
    SEPERATOR

    // Test Case 29: Random intervals
    cout << TEST << " 29\n";
    IntervalTree randomIntervalsTree;
    randomIntervalsTree.insertInterval(20, 30);
    randomIntervalsTree.insertInterval(5, 15);
    randomIntervalsTree.insertInterval(25, 35);
    randomIntervalsTree.insertInterval(10, 12);
    randomIntervalsTree.searchInterval(8, 14); // Expect: Found overlapping interval: [5, 30]
    SEPERATOR

    // Test Case 30: Random intervals
    cout << TEST << " 30\n";
    randomIntervalsTree.insertInterval(50, 60);
    randomIntervalsTree.insertInterval(70, 80);
    randomIntervalsTree.insertInterval(55, 65);
    randomIntervalsTree.insertInterval(75, 85);
    randomIntervalsTree.searchInterval(62, 78); // Expect: Found overlapping interval: [50, 85]
    SEPERATOR

    return 0;
}
