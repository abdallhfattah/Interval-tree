# Interval Tree

This C++ code implements an Interval Tree data structure for efficient interval searching. The Interval Tree is a binary search tree that stores intervals and allows for quick retrieval of intervals that overlap with a given query interval.

## Implementation Details

The code defines a class `IntervalTree`, which has methods for inserting intervals, searching for overlapping intervals, and printing the tree structure. The intervals are represented by a nested `Node` class, which is the building block of the Interval Tree.

### Class: `IntervalTree`

#### Public Methods:

1. `IntervalTree()`: Constructor for creating an empty Interval Tree.
2. `void insertInterval(int low, int high)`: Inserts a new interval into the tree.
3. `void searchInterval(int low, int high)`: Searches for intervals that overlap with the given query interval.
4. `void print()`: Prints the entire tree structure using Depth-First Search (DFS).
5. `void printRoot()`: Prints information about the root node.

#### Private Methods:

1. `Node* insertInterval(Node* node, int low, int high)`: Private method for recursively inserting intervals into the tree.
2. `bool intersection(Node* x, int low, int high)`: Private method to check if there is an intersection between two intervals.
3. `Node* searchInterval(Node* node, int low, int high)`: Private method for recursively searching for overlapping intervals.
4. `void dfs(Node* root)`: Private method for Depth-First Search traversal.


### TEST
1. Run the following command to build the project: `cmake --build build -j 12`
2. Run the following command to run the tests: `GTEST_COLOR=1 ctest --test-dir build --output-on-failure -j12`

### Example Usage:

```cpp
IntervalTree intervalTree;

// Insert intervals
intervalTree.insertInterval(10, 20);
intervalTree.insertInterval(30, 40);

// Search for overlapping intervals
intervalTree.searchInterval(15, 25);

// Print the tree structure
intervalTree.print();
