#include "BinarySearchTree.hpp"
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    BinaryTree tree;

    // Insert nodes
    tree.insertNode(9);
    tree.insertNode(7);
    tree.insertNode(15);
    tree.insertNode(10);
    tree.insertNode(17);
    tree.insertNode(8);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(2);

    // Vectors to store traversal results
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;

    // Traversals before deletion
    tree.inorderTreeWalk(tree.getRoot(), inorder);
    tree.preorderTreeWalk(tree.getRoot(), preorder);
    tree.postorderTreeWalk(tree.getRoot(), postorder);

    cout << "Initial tree:" << endl;
    cout << "Inorder: ";
    for (int v : inorder) cout << v << " ";
    cout << endl;

    cout << "Preorder: ";
    for (int v : preorder) cout << v << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int v : postorder) cout << v << " ";
    cout << endl;

    // Delete some nodes
    cout << "\nDeleting 15 (node with two children)..." << endl;
    tree.deleteNode(tree.getRoot(), 15);

    cout << "Deleting 4 (node with one child)..." << endl;
    tree.deleteNode(tree.getRoot(), 4);

    cout << "Deleting 2 (leaf node)..." << endl;
    tree.deleteNode(tree.getRoot(), 2);

    // Clear traversal vectors
    inorder.clear();
    preorder.clear();
    postorder.clear();

    // Traversals after deletion
    tree.inorderTreeWalk(tree.getRoot(), inorder);
    tree.preorderTreeWalk(tree.getRoot(), preorder);
    tree.postorderTreeWalk(tree.getRoot(), postorder);

    cout << "\nTree after deletions:" << endl;
    cout << "Inorder: ";
    for (int v : inorder) cout << v << " ";
    cout << endl;

    cout << "Preorder: ";
    for (int v : preorder) cout << v << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int v : postorder) cout << v << " ";
    cout << endl;

    // Height of tree
    cout << "Height: " << tree.heightOfTree(tree.getRoot()) << endl;

    // Search for a value
    Node* found = tree.searching(tree.getRoot(), 15);
    if (found)
        cout << "Found node with value: " << found->value << endl;
    else
        cout << "Node 15 not found." << endl;

    // Min / Max values
    Node* minNode = tree.minVal(tree.getRoot());
    Node* maxNode = tree.maxVal(tree.getRoot());

    if (minNode)
        cout << "Min value: " << minNode->value << endl;

    if (maxNode)
        cout << "Max value: " << maxNode->value << endl;

    // Validate BST
    bool valid = tree.isValid(tree.getRoot(), INT_MIN, INT_MAX);
    cout << "Is valid BST: " << (valid ? "Yes" : "No") << endl;

    return 0;
}