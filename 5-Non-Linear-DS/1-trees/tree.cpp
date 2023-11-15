// #include <iostream>

// // BST
// struct TreeNode {
//     int data;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
// };

// TreeNode* insert(TreeNode* root, int value) {
//     if (root == nullptr) {
//         return new TreeNode(value);
//     }
//     if (value < root->data) {
//         root->left = insert(root->left, value);
//     } else {
//         root->right = insert(root->right, value);
//     }
//     return root;
// }
// void displayInOrder(TreeNode* root) {
//     if (root != nullptr) {
//         displayInOrder(root->left);
//         std::cout << root->data << " ";
//         displayInOrder(root->right);
//     }
// }
// void displayPreOrder(TreeNode* root) {
//     if (root != nullptr) {
//         std::cout << root->data << " ";
//         displayPreOrder(root->left);
//         displayPreOrder(root->right);
//     }
// }
// void displayPostOrder(TreeNode* root) {
//     if (root != nullptr) {
//         displayPostOrder(root->left);
//         displayPostOrder(root->right);
//         std::cout << root->data << " ";
//     }
// }
// int main() {
//     TreeNode* root = nullptr;
//     root = insert(root, 23);
//     root = insert(root, 34);
//     root = insert(root, 45);
//     root = insert(root, 60);
//     root = insert(root, 69);
//     // First inOrder traversal
//     std::cout << "In Order traversal\n";
//     displayInOrder(root);
//     std::cout << "\n\n";
//    // Pre Order Traversal
//     std::cout << "Pre Order Traversal\n";
//     displayPreOrder(root);
//     std::cout << "\n\n";
//     std::cout << "Post Order Traversal\n";
//     displayPostOrder(root);
//     return 0;
// }
//-----------------------------simple tree implementation-----------
#include <iostream>
struct Node {
    int data;
    Node* firstChild;
    Node* nextChild;
    Node(int value) : data(value), firstChild(nullptr), nextChild(nullptr) {}
};
class Tree {
public:
    Node* root;
    Tree() : root(nullptr) {}
    Node* insert(Node* parent, int value) {
        Node* newNode = new Node(value);

        if (parent == nullptr) {
            // If parent is null, set the root
            root = newNode;
        } else {
            // Insert the new node as a child of the parent
            if (parent->firstChild == nullptr) {
                parent->firstChild = newNode;
            } else {
                Node* current = parent->firstChild;
                while (current->nextChild != nullptr) {
                    current = current->nextChild;
                }
                current->nextChild = newNode;
            }
        }
        return newNode;
    }
    // Function to display the tree
    void display(Node* current, int depth = 0) {
        if (current == nullptr) {
            return;
        }
        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        // Display the data of the current node
        std::cout << current->data << std::endl;
        Node* child = current->firstChild;
        while (child != nullptr) {
            display(child, depth + 1);
            child = child->nextChild;
        }
    }
};
int main() {
    Tree tree;
    // Create root node and three children
    Node* root = tree.insert(nullptr, 1);
    Node* child1 = tree.insert(root, 2);
    Node* child2 = tree.insert(root, 3);
    Node* child3 = tree.insert(root, 4);
    Node* grandChild1 = tree.insert(child1, 5);
    Node* grandChild2 = tree.insert(child2, 6);
    Node* grandChild3 = tree.insert(child3, 7);
    tree.display(tree.root);
    return 0;
}
