#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left, *right;

    Node() {}
    Node(int value) {
        this -> value = value;
        left = right = NULL;
    }
};

class Tree {
private:
    Node *root;
public:
    Tree() {
        this->root = new Node();
        root->left = NULL;
        root->right = NULL;
    }

    Tree(Node *root) {
        this->root = root;
    }

    ~Tree() {
        deleteTree(root);
    }

    void printInPreorder() const {
        std::cout << "PREORDER TRAVERSAL:\n";
        preOrderTraverse(root);
        std::cout << "\n\n\n";
    }

    void printInInorder() const {
        std::cout << "INORDER TRAVERSAL:\n";
        inOrderTraverse(root);
        std::cout << "\n\n\n";
    }

    void printInPostOrder() const {
        std::cout << "POSTORDER TRAVERSAL:\n";
        postOrderTraverse(root);
        std::cout << "\n\n\n";
    }

private:
    void deleteTree(Node *&root) {
        if (root) {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
            root = NULL;
        }
    }

    void preOrderTraverse(Node *root) const {
        if (root) {
            std::cout << root->value << ", ";
            preOrderTraverse(root->left);
            preOrderTraverse(root->right);

        }
    }
    void inOrderTraverse(Node *root) const {
        if (root) {
            inOrderTraverse(root->left);
            std::cout << root->value << ", ";
            inOrderTraverse(root->right);

        }
    }
    void postOrderTraverse(Node *root) const {
        if (root) {
            postOrderTraverse(root->left);
            postOrderTraverse(root->right);
            std::cout << root->value << ", ";
        }
    }

public:
    static void createTree(Node*& root) {
        int value;  char c;
        cout<< "root: "; cin>>value;
        root = new Node(value);
        cout<< "Has left subtree: "<<value<<" ?(y/n)";
        cin>> c;
        if(c == 'y') {
            createTree(root -> left) ;
        } else {
            root->left = NULL;
        }
        cout<< "Has right subtree: "<<value<<" ?(y/n)";
        cin>> c;
        if(c == 'y') {
            createTree(root -> right) ;
        } else {
            root->right = NULL;
        }
    }
};

int main() {
    Node* root = new Node();
    Tree::createTree(root);
    Tree* t = new Tree(root);

    t -> printInPreorder();
    t -> printInInorder();
    t -> printInPostOrder();

    delete t;
    return 0;
}
