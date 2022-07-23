#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char sym;
    int val = 0;
    vector<Node*> children;

    Node(char sym, int val) {
        this -> sym = sym;
        this -> val = val;
    }
};

/**
 * Contains the `word` and `value` properties for a specific tree path.
 */
struct TreeNodeProps {
    string word;
    int value;
};

TreeNodeProps& calculatePathProps(vector<Node>* nodes) {
    TreeNodeProps* treeNodeProps = new TreeNodeProps();
    std::string word;

    for (Node n: *nodes) {
        treeNodeProps -> word += n.sym;
        treeNodeProps -> value += n.val;
    }
    return *treeNodeProps;
}

/**
 * Get TreeNodeProperties for all paths starting from a given node
 */
void get_props_for_all_paths(Node* root, vector<Node>* &path, vector<TreeNodeProps>*&result) {
    if (!root) {
        return;
    }

    //1. добавяме текущия връх в дървото
    path->push_back(*root);

    //2. ако текущият връх е листо, калкулираме стойностите на пътя
    // иначе -> //! За всички наследници на текушия връх пускаме същата функция!
    if (root->children.empty()) {
        result->push_back(calculatePathProps(path));
    }
    else {
        for (Node *node: root->children) {
            get_props_for_all_paths(node, path, result);
        }
    }
    path->pop_back();
}

vector<TreeNodeProps>*& get_props_for_all_paths_from_root(Node *root) {
    vector<TreeNodeProps>* result = new vector<TreeNodeProps>();
    vector<Node>* path = new vector<Node>();

    get_props_for_all_paths(root, path, result);

    return result;
}


vector<TreeNodeProps>*& mergeFilteredTreeNodeProps(vector<TreeNodeProps> &paths1, vector<TreeNodeProps> &paths2) {
    vector<TreeNodeProps>* result = new vector<TreeNodeProps>();

    for (TreeNodeProps p1: paths1) {
        for (TreeNodeProps p2: paths2) {
            if (p1.word.compare(p2.word)== 0) {
                result->push_back(p1);
                result->push_back(p2);
            }
        }
    }
    return result;
}


int sumVal(Node *u, Node *v) {
    vector<TreeNodeProps> allPathsPropsForU = *get_props_for_all_paths_from_root(u);
    vector<TreeNodeProps> allPathsPropsForV = *get_props_for_all_paths_from_root(v);

    vector<TreeNodeProps>* &allPathsHavingEqualWords = mergeFilteredTreeNodeProps(allPathsPropsForU, allPathsPropsForV);

    int sum = 0;
    for(TreeNodeProps treeNodeProps: *allPathsHavingEqualWords) {
        sum += treeNodeProps.value;
    }

    return sum;
}

int main() {
    Node* u = new Node('f', 2);
    Node* u1 = new Node('i', 3);
    Node* u2 = new Node('o', 5);
    Node* u3 = new Node('f', -1);
    Node* u4 = new Node('z', 4);
    Node* u5 = new Node('f', 0);
    Node* u6 = new Node('m', 1);
    Node* u7 = new Node('y', 33);

    Node* v1 = new Node('i', -7);
    Node* v2 = new Node ('0',0);
    Node* v3 = new Node ('f',6);
    Node* v4 = new Node ('f',6);
    Node* v5 = new Node ('y',11);


    v4->children.push_back(v5);
    v3->children.push_back(v4);
    v1->children.push_back(v3);
    v1->children.push_back(v2);

    u5->children.push_back(u7);
    u3->children.push_back(u5);
    u3->children.push_back(u6);
    u1->children.push_back(u3);
    u1->children.push_back(u4);
    u->children.push_back(u1);
    u->children.push_back(u2);

    Node* v = new Node('f',1);

    v-> children.push_back(v1);
    v->children.push_back(u);


    std::cout << sumVal(u, v) << std::endl;

    return 0;
}
