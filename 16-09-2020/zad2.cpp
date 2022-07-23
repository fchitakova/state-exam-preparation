#include <iostream>

using namespace std;

struct Node {
    char text;
    Node *left, *right;

    Node(char text) {
        this->text = text;
        left = right = NULL;
    }
};

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(Node *root) {
    if (!root) return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(root->left);
        int rheight = height(root->right);

        /* use the larger one */
        if (lheight > rheight)return lheight + 1;
        return rheight + 1;
    }
}

void printCurrentLevel(Node *root, int level) {
    if (!root) {
        std::cout << ' ';
        return;
    }
    if (level == 1) cout << root->text;
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printText(Node *root) {
    int heightOfTree = height(root);
    for (int i = 1; i <= heightOfTree; i++) {
        printCurrentLevel(root, i);
        std::cout << endl;
    }
}


int main() {
    Node *i = new Node('i');
    Node *v = new Node('v');
    Node *d = new Node('d');
    d->left = v, d->right = i;
    Node *m = new Node('m');
    Node *e = new Node('e');
    Node *l = new Node('l');
    l->left = e, l->right = m;
    Node *l1 = new Node('l');
    Node *b = new Node('b');
    Node *o = new Node('o');
    o->left = b, o->right = l1;
    Node *o1 = new Node('o');
    o1->left = o, o1->right = l;
    Node *m1 = new Node('m');
    m1->left = o1, m1->right = d;

    Node *o3 = new Node('o');
    Node *r = new Node('r');
    Node *s = new Node('s');
    s->left = r, s->right = o3;
    Node *o4 = new Node('o');
    o4->right = s;
    Node *p = new Node('p');
    Node *t = new Node('t');
    t->right = p;

    Node *udiv = new Node('!');
    Node *g = new Node('g');
    g->right = udiv;

    Node *s1 = new Node('s');
    Node *n = new Node('n');
    n->left = s1;

    Node *a = new Node('a');
    a->left = n, a->right = g;

    Node *g1 = new Node('g');
    g1->left = a, g1->right = t;

    Node *a2 = new Node('a');
    a2->left = g1, a2->right = o4;

    Node *I = new Node('I');
    I->left = a2, I->right = m1;


    std::cout << height(I) << std::endl;
    printText(I);
    return 0;
}
