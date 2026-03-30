#include "RedBlackTree.hpp"

void printTree(Node* node, int indent = 0) {
    if (!node) return;
    printTree(node->right, indent + 4);
    for (int i = 0; i < indent; i++) std::cout << " ";
    cout << node->value << (node->color ? "(R)" : "(B)") << "\n";
    printTree(node->left, indent + 4);
}

int main() {
    RedBlackTree tree;

    // ── Insert ──────────────────────────────────────────
    cout << "=== Inserting: 10 20 30 15 25 5 1 ===\n";
    tree.insertNode(10);
    tree.insertNode(20);
    tree.insertNode(30);
    tree.insertNode(15);
    tree.insertNode(25);
    tree.insertNode(5);
    tree.insertNode(1);
    printTree(tree.getRoot());

    // ── Height ──────────────────────────────────────────
    cout << "\n=== Height of tree: "
              << tree.heightOfTree(tree.getRoot()) << " ===\n";

    // ── Min / Max ────────────────────────────────────────
    cout << "\n=== Min value: "
              << tree.minValNode()->value << " ===\n";
    cout << "=== Max value: "
              << tree.maxValNode()->value << " ===\n";

    // ── Search ───────────────────────────────────────────
    cout << "\n=== Searching for 15: ";
    Node* found = tree.searching(tree.getRoot(), 15);
    cout << (found ? "Found!" : "Not found!") << " ===\n";

    cout << "=== Searching for 99: ";
    found = tree.searching(tree.getRoot(), 99);
    cout << (found ? "Found!" : "Not found!") << " ===\n";

    // ── succ ────────────────────────────────────────
    cout << "\n=== succ of 15: ";
    Node* succ = tree.successor(15);
    cout << (succ ? std::to_string(succ->value) : "none") << " ===\n";

    cout << "=== succ of 30 (max): ";
    succ = tree.successor(30);
    cout << (succ ? std::to_string(succ->value) : "none") << " ===\n";

    // ── Delete red leaf ──────────────────────────────────
    cout << "\n=== Deleting 1 (red leaf) ===\n";
    tree.deleteNode(1);
    printTree(tree.getRoot());

    // ── Delete black node with two children ──────────────
    cout << "\n=== Deleting 20 (black node, two children) ===\n";
    tree.deleteNode(20);
    printTree(tree.getRoot());

    // ── Delete black leaf (triggers fixup) ───────────────
    cout << "\n=== Deleting 5 (triggers fixup) ===\n";
    tree.deleteNode(5);
    printTree(tree.getRoot());

    // ── Delete root ──────────────────────────────────────
    cout << "\n=== Deleting root ===\n";
    tree.deleteNode(tree.getRoot()->value);
    printTree(tree.getRoot());

    // ── Delete remaining nodes ───────────────────────────
    cout << "\n=== Deleting all remaining nodes ===\n";
    while (tree.getRoot()) {
        cout << "Deleting: " << tree.getRoot()->value << "\n";
        tree.deleteNode(tree.getRoot()->value);
        printTree(tree.getRoot());
        cout << "\n";
    }

    cout << "=== Tree is empty ===\n";
    return 0;
}