#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class BinarySearchTree {
private:
    Node *root;
public:
    BinarySearchTree() {
        this->root = NULL;
    }

    ~BinarySearchTree() {
        deleteBST(root);
    }

    void addValue(const int &value) {
        addNode(this->root, value);
    }

    void deleteValue(const int &value) {
        deleteNode(this->root, value);
    }

    bool searchValue(const int &value) {
        return searchNode(this->root, value) != NULL;
    }

private:
    void deleteBST(Node *&root) {
        if (!root)
            return;
        if (root->left)
            deleteBST(root->left);
        if (root->right)
            deleteBST(root->right);
        delete root;
        root = NULL;
    }

    void addNode(Node *&root, const int &data) {
        if (!root) {
            root = new Node(data);
            return;
        }
        if (data < root->data)
            addNode(root->left, data);
        if (data >= root->data)
            addNode(root->right, data);
    }

    void deleteNode(Node *&root, const int &data) {
        //в този случай няма какво да трием
        if (!root)
            return;
        if (data < root->data)
            deleteNode(root->left, data);
        if (data > root->data)
            deleteNode(root->right, data);
        else {
            Node *p;
            //! Изтриване на възел с едно дете: изтриваме възела и го подменяме с детето му.
            if (!root->left) {
                p = root;
                root = root->right;
                delete p;
            } else if (!root->right) {
                p = root;
                root = root->left;
                delete root;
            }
                //ако възелът, който изтриваме има 2 наследника
            else {
                p = root->left;
                while (p->right) p = p->right;
                root->data = p->data;
                deleteNode(root->left, p->data);
            }
        }

    }

    Node* searchNode(Node *&root, const int &data) {
        if (root == NULL || root->data == data)
            return root;

        // Key is greater than root's key
        if (root->data < data)
            return searchNode(root->right, data);

        // Key is smaller than root's key
        return searchNode(root->left, data);
    }
};


int main() {
    BinarySearchTree *bst = new BinarySearchTree();
    bst->addValue( 50);
    bst->addValue( 30);
    bst->addValue( 20);
    bst->addValue( 40);
    bst->addValue( 70);
    bst->addValue( 60);
    bst->addValue( 80);
    bst->deleteValue(70);
    std::cout<<bst->searchValue(-15)<<std::endl;
    std::cout<<bst->searchValue(60)<<std::endl;

    return 0;
}
